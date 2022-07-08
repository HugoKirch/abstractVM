/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Operand
*/

#pragma once

#include "IOperand.hpp"

namespace avm {
    class Operand : public IOperand {
        public:
            Operand();
            ~Operand() = 0;
            std::shared_ptr<IOperand> operator+(const std::shared_ptr<IOperand> rhs) const;
            std::shared_ptr<IOperand> operator-(const std::shared_ptr<IOperand> rhs) const;
            std::shared_ptr<IOperand> operator*(const std::shared_ptr<IOperand> rhs) const;
            std::shared_ptr<IOperand> operator/(const std::shared_ptr<IOperand> rhs) const;
            std::shared_ptr<IOperand> operator%(const std::shared_ptr<IOperand> rhs) const;

    };
}
