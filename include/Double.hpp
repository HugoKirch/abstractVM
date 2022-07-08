/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Double
*/

#pragma once

#include "Operand.hpp"
#include "Error.hpp"
#include <array>
#include <limits>

namespace avm{
    class Double : public Operand {
        public:
            Double(std::string v);
            ~Double();
            std::string toString() const;
            eOperandType getType() const;

        private:
            bool negative;
            double value;
            size_t decimal;
    };
}
