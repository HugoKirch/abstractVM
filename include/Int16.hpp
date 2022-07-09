/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Int16
*/

#pragma once

#include "Operand.hpp"
#include "Error.hpp"
#include <array>

namespace avm{
    class Int16 : public Operand {
        public:
            Int16(std::string v);
            ~Int16();
            std::string toString() const;
            eOperandType getType() const;
            void setValue(std::string v);

        private:
            bool negative;
            short value;
    };
}
