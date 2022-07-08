/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Float
*/

#include "Float.hpp"
#include "Factory.hpp"

avm::Float::Float(std::string v)
{
    this->value = std::stof(v);
}

avm::Float::~Float()
{
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
