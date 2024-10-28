//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once

namespace atlas::generator {
    template<class T>
    class Generator {
        public:
            virtual ~Generator() = default;
            virtual T next() = 0;
    };
}