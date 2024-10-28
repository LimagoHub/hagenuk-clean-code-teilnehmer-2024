cmake_minimum_required(VERSION 3.28)
project(VectorFillerUebung)

set(CMAKE_CXX_STANDARD 17)

add_executable(VectorFillerUebung main.cpp
        generator/Generator.h
        collections/VectorFactory.h
        time/Stopwatch.h
        time/impl/StopwatchImpl.h
        collections/AbstractVectorFactory.h
        collections/impl/decorators/VectorFactoryBenchmarkDecorator.h
        client/impl/ClientImpl.h
        bootstrap/Bootstrap.h
        generator/GeneratorBuilder.h
        collections/impl/parallel/VectorFactoryParallelImpl.h)
