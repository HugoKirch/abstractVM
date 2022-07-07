/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Factory
*/

#pragma once

#include <string>
#include <array>
#include "IOperand.hpp"

namespace avm {
    class Factory {
        public:
            static IOperand *createOperand(eOperandType type, const std::string &value);
            static std::array<IOperand *(Factory::*)(const std::string &), 6> functions;
        private:
            IOperand *createInt8(const std::string &value);
            IOperand *createInt16(const std::string &value);
            IOperand *createInt32(const std::string &value);
            IOperand *createFloat(const std::string &value);
            IOperand *createDouble(const std::string &value);
            IOperand *createBigDecimal(const std::string &value);
    };
}
