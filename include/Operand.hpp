/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Operand
*/

#pragma once

#include "IOperand.hpp"
#include "Utils.hpp"
#include "OperandData.hpp"

namespace avm {
    template <typename T>
    class Operand : public IOperand {
        private:
            std::shared_ptr<avm::OperandData<T>> data;
            avm::eOperandType type;
            T value;

        public:
            Operand(std::string v, std::shared_ptr<avm::OperandData<T>> data)
            : data(data)
            {
                try {
                    this->value = data->getFunction()(v);
                }
                catch (std::exception &e) {
                    throw Error("Invalid " + data->getName() + " format: " + v);
                }
                if (v != std::to_string(this->value))
                    throw Error("Invalid " + data->getName() + " format: " + v);
            }
            ~Operand()
            {

            }
            inline std::string toString() const
            {
                return (avm::Utils::setPrecision<T>(this->value, data->getPrecision()));
            }
            inline avm::eOperandType getType()
            {
                return (this->type);
            }
            std::shared_ptr<avm::IOperand> operator+(const std::shared_ptr<avm::IOperand> rhs) const;
            std::shared_ptr<avm::IOperand> operator-(const std::shared_ptr<avm::IOperand> rhs) const;
            std::shared_ptr<avm::IOperand> operator*(const std::shared_ptr<avm::IOperand> rhs) const;
            std::shared_ptr<avm::IOperand> operator/(const std::shared_ptr<avm::IOperand> rhs) const;
            std::shared_ptr<avm::IOperand> operator%(const std::shared_ptr<avm::IOperand> rhs) const;
        };
}
