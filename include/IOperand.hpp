/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** IOperand
*/

#pragma once

#include <string>

namespace avm {
    enum eOperandType {
        Int8,
        Int16,
        Int32,
        Float,
        Double,
        BigDecimal
    };
    class IOperand {
        public:
            virtual std::string toString() const = 0; // string that represents the instance
            virtual eOperandType getType() const = 0; // returns the type of instance
            virtual IOperand *operator+(const IOperand &rhs) const = 0; // sum
            virtual IOperand *operator-(const IOperand &rhs) const = 0; // difference
            virtual IOperand *operator*(const IOperand &rhs) const = 0; // product
            virtual IOperand *operator/(const IOperand &rhs) const = 0; // quotient
            virtual IOperand *operator%(const IOperand &rhs) const = 0; // modulo
            virtual ~IOperand() {}
    };
}