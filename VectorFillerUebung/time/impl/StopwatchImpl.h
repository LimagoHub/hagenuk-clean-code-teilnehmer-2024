//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once
#include "../Stopwatch.h"
namespace atlas::time {
    class StopwatchImpl :public Stopwatch{
        std::chrono::high_resolution_clock::time_point start_;
        std::chrono::high_resolution_clock::time_point end_;
    public:
        StopwatchImpl() = default;

        ~StopwatchImpl() override = default;

        auto start() -> void override {
            start_ = std::chrono::high_resolution_clock::now();
        }

        auto stop() -> void override {
            end_ = std::chrono::high_resolution_clock::now();
        }



        auto getDurationToMilliseconds() -> std::chrono::milliseconds override {
            return std::chrono::duration_cast<std::chrono::milliseconds>(end_-start_);
        }

    };
}
