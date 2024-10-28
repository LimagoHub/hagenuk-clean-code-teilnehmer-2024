//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once
#pragma once
#include <iostream>
#include <memory>
#include <thread>
#include "../client/impl/ClientImpl.h"
#include "../generator/impl/random/MersenneTwisterNumberGeneratorFactory.h"
#include "../collections/impl/builder/VectorFactoryBuilder.h"

namespace atlas::bootstrap {
    class Bootstrap {
        using VECTOR_FACTORY = std::unique_ptr<atlas::collection::VectorFactory<int>>;

        using GENERATOR_BUILDER = std::unique_ptr<generator::GeneratorBuilder<int>>;
        using CLIENT = std::unique_ptr<atlas::client::Client>;

        static void create(size_t threadCount) {

            auto generatorBuilder = createGeneratorBuilder();
            atlas::collection::VectorFactoryBuilder<int>::setThreadCount(threadCount);
            atlas::collection::VectorFactoryBuilder<int>::setBenchmark(true);
            atlas::collection::VectorFactoryBuilder<int>::setLogger(true);
            atlas::collection::VectorFactoryBuilder<int>::setSecure(true);
            auto vectorFiller = atlas::collection::VectorFactoryBuilder<int>::createWithGeneratorBuilder(std::move(generatorBuilder));
            auto client = createClient(std::move(vectorFiller));

            client->doSomethingWithLargeVector();
        }

        static GENERATOR_BUILDER createGeneratorBuilder() {
            GENERATOR_BUILDER generatorBuilder = std::make_unique<atlas::generator::MersenneTwisterNumberGeneratorFactory>();
            return generatorBuilder;
        }


        static CLIENT createClient(VECTOR_FACTORY factory) {
            CLIENT client = std::make_unique<atlas::client::VectorClientImpl>(std::move(factory));
            return client;
        }



    public:


        auto startApplication()-> void const {
            const size_t availableProcessors = std::thread::hardware_concurrency();
            for (int threadCount = 0; threadCount <= availableProcessors + 1; ++threadCount) {
                std::cout << "Starte Messung mit " << threadCount << " Threads" << std::endl;
                create(threadCount);
            }

        }

    };
}
