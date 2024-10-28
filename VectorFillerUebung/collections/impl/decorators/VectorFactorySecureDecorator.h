//
// Created by JoachimWagner on 11.04.2024.
//

#pragma once

#include <iostream>
#include "AbstractVectorFactoryDecorator.h"
#include "../../../time/impl/StopwatchImpl.h"
namespace atlas::collection {

    template<class T>
    class VectorFactorySecureDecorator: public AbstractVectorFactoryDecorator<T> {
        using VectorFactoryPointer = std::unique_ptr<VectorFactory<T>>;
        using VECTOR = std::shared_ptr<std::vector<T>>;

    public:
        //~VectorFactoryBenchmarkDecorator() override= default;
        explicit VectorFactorySecureDecorator(VectorFactoryPointer vectorFactoryPointer_)
                :AbstractVectorFactoryDecorator<T>{std::move(vectorFactoryPointer_)}{}


        auto createAndFillVector(size_t size) -> VECTOR override {

            std::cout << "Du kommst hier rein" << std::endl;
            return this->vectorFactoryPointer->createAndFillVector(size);


        }

    };

} // collections
