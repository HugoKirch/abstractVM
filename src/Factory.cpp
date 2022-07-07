/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Factory
*/

#include "Factory.hpp"

std::array<avm::IOperand *(avm::Factory::*)(const std::string &), 6> avm::Factory::functions = {
    &avm::Factory::createInt8,
    &Factory::createInt16,
    &Factory::createInt32,
    &Factory::createFloat,
    &Factory::createDouble,
    &Factory::createBigDecimal
};

avm::IOperand *avm::Factory::createOperand(avm::eOperandType type, const std::string &value)
{
    (void)value;
    auto function = avm::Factory::functions.at(type);
    (void)function;
    return (nullptr);
   // return ((function)(value));
}

avm::IOperand *avm::Factory::createInt8(const std::string &value)
{
    (void)value;
    return (nullptr);
}
avm::IOperand *avm::Factory::createInt16(const std::string &value)
{
    (void)value;
    return (nullptr);
}
avm::IOperand *avm::Factory::createInt32(const std::string &value)
{
    (void)value;
    return (nullptr);
}
avm::IOperand *avm::Factory::createFloat(const std::string &value)
{
    (void)value;
    return (nullptr);
}
avm::IOperand *avm::Factory::createDouble(const std::string &value)
{
    (void)value;
    return (nullptr);
}
avm::IOperand *avm::Factory::createBigDecimal(const std::string &value)
{
    (void)value;
    return (nullptr);
}