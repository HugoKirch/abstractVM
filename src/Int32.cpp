/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Int32
*/

#include "Int32.hpp"
#include "Factory.hpp"

avm::Int32::Int32(std::string v)
{
    setValue(v);
}

avm::Int32::~Int32()
{
}

void avm::Int32::setValue(std::string v)
{
    try {
        this->value = std::stoi(v);
    }
    catch (std::exception &e) {
        throw Error("Invalid int32 format: " + v);
    }
    if (v != std::to_string(this->value))
        throw Error("Invalid int32 format: " + v);
}

avm::eOperandType avm::Int32::getType() const
{
    return (avm::INT32);
}

std::string avm::Int32::toString() const
{
    std::string str = std::to_string(this->value);

  /*  if (this->value.size() == 0)
        return (0);
    if (this->negative)
        str += '-';
    for (signed char v : this->value)
        str += v;*/
    return (str);
}
