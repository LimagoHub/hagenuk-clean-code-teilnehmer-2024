//
// Created by JoachimWagner on 10.04.2024.
//
#include <vector>
#include <memory>
#include <iostream>
#include "../Client.h"
#include "../../collections/VectorFactory.h"

namespace atlas::client {

    class VectorClientImpl: public Client {
        using VECTOR = std::unique_ptr<atlas::collection::VectorFactory<int> >;

        VECTOR factory;


    public:

        explicit VectorClientImpl(VECTOR factory) : factory(std::move(factory)) {}

        ~VectorClientImpl() override = default;

        auto doSomethingWithLargeVector() ->void  override{

            auto v = factory->createAndFillVector(INT_MAX / 8);
            for (int i = 0; i < 3; ++i) {
                std::cout << v->at(i) << std::endl;
            }
        }
    };

}
