/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Int8
*/

#pragma once

#include "Operand.hpp"
#include "Error.hpp"
#include <array>

namespace avm{
    class Int8 : public Operand {
        public:
            Int8(std::string v);
            ~Int8();
            std::string toString() const;
            eOperandType getType() const;

        private:
            bool negative;
            char value;
    };
}
