//
// Created by JoachimWagner on 11.04.2024.
//

#pragma once

#include <iostream>
#include "AbstractVectorFactoryDecorator.h"
#include "../../../time/impl/StopwatchImpl.h"
namespace atlas::collection {

    template<class T>
    class VectorFactoryLoggerDecorator: public AbstractVectorFactoryDecorator<T> {
        using VectorFactoryPointer = std::unique_ptr<VectorFactory<T>>;
        using VECTOR = std::shared_ptr<std::vector<T>>;

    public:
        //~VectorFactoryBenchmarkDecorator() override= default;
        explicit VectorFactoryLoggerDecorator(VectorFactoryPointer vectorFactoryPointer_)
                :AbstractVectorFactoryDecorator<T>{std::move(vectorFactoryPointer_)}{}


        auto createAndFillVector(size_t size) -> VECTOR override {

            std::cout << "createAndFillVector wurde mit Size: " << size << " aufgerufen" << std::endl;
            return this->vectorFactoryPointer->createAndFillVector(size);


        }

    };

} // collections
