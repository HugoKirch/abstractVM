/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Int8
*/

#include "Int8.hpp"
#include "Factory.hpp"

avm::Int8::Int8()
{
}

avm::Int8::~Int8()
{
}

avm::eOperandType avm::Int8::getType() const
{
    return (avm::Int8);
}

std::string avm::Int8::toString() const
{
    std::string str;

    if (this->integer.size() == 0)
        return (0);
    for (signed char v : this->integer)
        str += v;
    return (str);
}
