/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** BigDecimal
*/

#include "BigDecimal.hpp"
#include "BigDecimal.hpp"
#include "Utils.hpp"
#include <decimal/decimal>

avm::BigDecimal::BigDecimal(std::string v)
{
    setValue(v);
}

avm::BigDecimal::~BigDecimal()
{
}

void avm::BigDecimal::setValue(std::string v)
{
    try {
        this->value = std::stold(v);
    }
    catch (std::exception &e) {
        throw Error("Invalid bigdecimal format: " + v);
    }
    std::string pv = avm::Utils::removeTrailingZero(v);
    if (v.compare(pv))
        throw Error("Invalid bigdecimal format: " + v);
}

avm::eOperandType avm::BigDecimal::getType() const
{
    return (avm::BIGDECIMAL);
}

std::string avm::BigDecimal::toString() const
{
    std::string str = avm::Utils::setPrecision<double>(this->value, 15);
   // size_t i;

 /*   if (this->value.size() == 0)
        return (0);
    if (this->negative)
        str += '-';
    if (this->decimal == (size_t)0)
        str += '0';
    for (signed char v : this->value) {
        if (i == this->decimal)
            str += '.';
        str += v;
        i++;
    }*/
    return (str);
}
