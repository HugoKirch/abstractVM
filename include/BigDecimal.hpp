/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** BigDecimal
*/

#pragma once

#include "Operand.hpp"
#include "Error.hpp"
#include <array>
#include <limits>

namespace avm{
    class BigDecimal : public Operand {
        public:
            BigDecimal(std::string v);
            ~BigDecimal();
            std::string toString() const;
            eOperandType getType() const;

        private:
            bool negative;
            long double value;
            size_t decimal;
    };
}
