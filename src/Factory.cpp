/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Factory
*/

#include "Factory.hpp"

std::array<std::shared_ptr<avm::IOperand> (*)(const std::string &), 6> avm::Factory::functions = {
    &avm::Factory::createInt8,
    &avm::Factory::createInt16,
    &avm::Factory::createInt32,
    &avm::Factory::createFloat,
    &avm::Factory::createDouble,
    &avm::Factory::createBigDecimal
};

std::shared_ptr<avm::IOperand> avm::Factory::createOperand(avm::eOperandType type, const std::string &value)
{
    auto function = avm::Factory::functions.at(type);

    return (function(value));
}

std::shared_ptr<avm::IOperand> avm::Factory::createInt8(const std::string &value)
{
    return (std::make_shared<avm::Int8>(value));
}
std::shared_ptr<avm::IOperand> avm::Factory::createInt16(const std::string &value)
{
    return (std::make_shared<avm::Int16>(value));
}
std::shared_ptr<avm::IOperand> avm::Factory::createInt32(const std::string &value)
{
    return (std::make_shared<avm::Int32>(value));
}
std::shared_ptr<avm::IOperand> avm::Factory::createFloat(const std::string &value)
{
    return (std::make_shared<avm::Float>(value));
}
std::shared_ptr<avm::IOperand> avm::Factory::createDouble(const std::string &value)
{
    return (std::make_shared<avm::Double>(value));
}
std::shared_ptr<avm::IOperand> avm::Factory::createBigDecimal(const std::string &value)
{
    return (std::make_shared<avm::BigDecimal>(value));
}