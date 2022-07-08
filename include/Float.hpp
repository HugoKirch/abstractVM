/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Float
*/

#pragma once

#include "Operand.hpp"
#include <array>
#include <limits>

namespace avm{
    class Float : public Operand {
        public:
            Float(std::string v);
            ~Float();
            std::string toString() const;
            eOperandType getType() const;

        private:
            bool negative;
            float value;
            size_t decimal;
    };
}
