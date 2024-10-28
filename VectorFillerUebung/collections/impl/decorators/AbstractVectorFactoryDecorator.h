//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once
#include <memory>
#include "../../VectorFactory.h"
namespace atlas::collection {
    template<class T>
    class AbstractVectorFactoryDecorator : public VectorFactory<T> {

        using VectorFactoryPointer = std::unique_ptr<VectorFactory<T>>;
    protected:

        VectorFactoryPointer vectorFactoryPointer;

    public:
        virtual ~AbstractVectorFactoryDecorator() = default;

        AbstractVectorFactoryDecorator(VectorFactoryPointer vectorFactoryPointer)
                : vectorFactoryPointer(std::move(vectorFactoryPointer)) {}

    };
}