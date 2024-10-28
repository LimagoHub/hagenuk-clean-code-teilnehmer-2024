//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once

namespace atlas::client {
    class Client {

    public:
        virtual ~Client() = default;
        virtual void doSomethingWithLargeVector() = 0;

    };

}
