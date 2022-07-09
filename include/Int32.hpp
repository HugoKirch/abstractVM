/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Int32
*/

#pragma once

#include "Operand.hpp"
#include "Error.hpp"
#include <array>

namespace avm{
    class Int32 : public Operand {
        public:
            Int32(std::string v);
            ~Int32();
            std::string toString() const;
            eOperandType getType() const;
            void setValue(std::string v);

        private:
            bool negative;
            int value;
    };
}
