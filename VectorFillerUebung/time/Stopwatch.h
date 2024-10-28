//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once

#include <chrono>

namespace atlas::time {
    class Stopwatch {

    public:
        virtual ~Stopwatch()=default;

        virtual void start() = 0;
        virtual void stop() = 0;
        virtual std::chrono::milliseconds getDurationToMilliseconds() = 0;
    };

}
