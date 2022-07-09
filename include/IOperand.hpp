/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** IOperand
*/

#pragma once

#include <memory>
#include <string>

namespace avm {
    enum eOperandType {
        INT8,
        INT16,
        INT32,
        FLOAT,
        DOUBLE,
        BIGDECIMAL
    };
    class IOperand {
        public:
            virtual std::string toString() const = 0; // string that represents the instance
            virtual eOperandType getType() const = 0; // returns the type of instance
            virtual void setValue(std::string v) = 0;
            virtual std::shared_ptr<IOperand> operator+(const std::shared_ptr<IOperand> rhs) const = 0; // sum
            virtual std::shared_ptr<IOperand> operator-(const std::shared_ptr<IOperand> rhs) const = 0; // difference
            virtual std::shared_ptr<IOperand> operator*(const std::shared_ptr<IOperand> rhs) const = 0; // product
            virtual std::shared_ptr<IOperand> operator/(const std::shared_ptr<IOperand> rhs) const = 0; // quotient
            virtual std::shared_ptr<IOperand> operator%(const std::shared_ptr<IOperand> rhs) const = 0; // modulo
            virtual ~IOperand() = default;
    };
}