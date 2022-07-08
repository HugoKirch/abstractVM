/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Int8
*/

#include "Int8.hpp"
#include "Factory.hpp"

avm::Int8::Int8(std::string v)
{
    this->value = std::stoi(v);
}

avm::Int8::~Int8()
{
}

avm::eOperandType avm::Int8::getType() const
{
    return (avm::INT8);
}

std::string avm::Int8::toString() const
{
    std::string str = std::to_string(this->value);

/*    if (this->value.size() == 0)
        return (0);
    if (this->negative)
        str += '-';
    for (signed char v : this->value)
        str += v;*/
    return (str);
}