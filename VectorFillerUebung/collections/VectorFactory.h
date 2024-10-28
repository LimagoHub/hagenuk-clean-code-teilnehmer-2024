//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once
#include <vector>
#include <memory>

namespace atlas::collection {


    template<class T>
    class VectorFactory {
        using VECTOR_POINTER = std::shared_ptr<std::vector<T>>;

    public:
       virtual ~VectorFactory() = default;
       virtual VECTOR_POINTER createAndFillVector(const size_t size) = 0;


    };
}
