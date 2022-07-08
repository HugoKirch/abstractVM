/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Float
*/

#include "Float.hpp"
#include "Factory.hpp"
#include "Utils.hpp"

avm::Float::Float(std::string v)
{   
    setValue(v);
    
}

avm::Float::~Float()
{
}
#include <iostream>
void avm::Float::setValue(std::string v)
{
    try {
        this->value = std::stof(v);
    }
    catch (std::exception &e) {
        throw Error("Invalid float format: " + v);
    }
    if (v != avm::Utils::removeTrailingZero(std::to_string(this->value)))
        throw Error("Invalid float format: " + v);
}

avm::eOperandType avm::Float::getType() const
{
    return (avm::FLOAT);
}

std::string avm::Float::toString() const
{
    std::string str = std::to_string(this->value);
  /*  size_t i;

    if (this->value.size() == 0)
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
