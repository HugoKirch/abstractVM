/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Int8
*/

#pragma once

#include "IOperand.hpp"
#include <array>

namespace avm{
    class Int8 : public IOperand {
        public:
            Int8();
            ~Int8();
            std::string toString() const;
            eOperandType getType() const;

        private:
            bool negative;
            std::array<signed char, 8> integer;
    };
}
