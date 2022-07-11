/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** TBigDecimal
*/

#pragma once

#include "Operand.hpp"
#include "Error.hpp"
#include <array>
#include <limits>
#include <memory>

namespace avm{
    class TBigDecimal : public Operand {
        public:
            TBigDecimal(std::string v);
            ~TBigDecimal();
            std::string toString() const;
            eOperandType getType() const;
            void setValue(std::string v);
            std::shared_ptr<TBigDecimal> operator+(const std::shared_ptr<TBigDecimal> rhs);
            std::shared_ptr<TBigDecimal> operator-(const std::shared_ptr<TBigDecimal> rhs);
            std::shared_ptr<TBigDecimal> operator*(const std::shared_ptr<TBigDecimal> rhs);

        private:
            bool negative;
            std::string integer;
            std::string decimal;
            std::shared_ptr<avm::TBigDecimal> add(const std::shared_ptr<avm::TBigDecimal> rhs);
            std::shared_ptr<avm::TBigDecimal> sub(const std::shared_ptr<avm::TBigDecimal> rhs);
            std::shared_ptr<avm::TBigDecimal> mul(const std::shared_ptr<avm::TBigDecimal> rhs);
    };
}
