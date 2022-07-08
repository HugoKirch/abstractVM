/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Int16
*/

#include "Int16.hpp"
#include "Factory.hpp"

avm::Int16::Int16(std::string v)
{
    try {
        this->value = std::stoi(v);
    }
    catch (std::exception &e) {
        throw Error("Invalid int16 format: " + v);
    }
}

avm::Int16::~Int16()
{
}

avm::eOperandType avm::Int16::getType() const
{
    return (avm::INT16);
}

std::string avm::Int16::toString() const
{
    std::string str = std::to_string(this->value);

 /*   if (this->value.size() == 0)
        return (0);
    if (this->negative)
        str += '-';
    for (signed char v : this->value)
        str += v;*/
    return (str);
}
