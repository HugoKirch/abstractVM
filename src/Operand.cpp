/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Operand
*/

#include "Operand.hpp"
#include "Factory.hpp"

avm::Operand::Operand()
{
}

avm::Operand::~Operand()
{
}

#include <iostream>
std::shared_ptr<avm::IOperand> avm::Operand::operator+(const std::shared_ptr<avm::IOperand> rhs) const
{
    avm::eOperandType type = (this->getType() > rhs->getType()) ? this->getType() : rhs->getType();

    std::string value = avm::Factory::convert(type, std::to_string(std::stold(this->toString()) + std::stold(rhs->toString())));

    return (avm::Factory::createOperand(type, value));
}
std::shared_ptr<avm::IOperand> avm::Operand::operator-(const std::shared_ptr<avm::IOperand> rhs) const
{
    avm::eOperandType type = (this->getType() > rhs->getType()) ? this->getType() : rhs->getType();

    std::string value = avm::Factory::convert(type, std::to_string(std::stold(this->toString()) - std::stold(rhs->toString())));

    return (avm::Factory::createOperand(type, value));

}
std::shared_ptr<avm::IOperand> avm::Operand::operator*(const std::shared_ptr<avm::IOperand> rhs) const
{
    avm::eOperandType type = (this->getType() > rhs->getType()) ? this->getType() : rhs->getType();

    std::string value = avm::Factory::convert(type, std::to_string(std::stold(this->toString()) * std::stold(rhs->toString())));

    return (avm::Factory::createOperand(type, value));
}
std::shared_ptr<avm::IOperand> avm::Operand::operator/(const std::shared_ptr<avm::IOperand> rhs) const
{
    avm::eOperandType type = (this->getType() > rhs->getType()) ? this->getType() : rhs->getType();

    std::string value = avm::Factory::convert(type, std::to_string(std::stold(this->toString()) / std::stold(rhs->toString())));

    return (avm::Factory::createOperand(type, value));
}
std::shared_ptr<avm::IOperand> avm::Operand::operator%(const std::shared_ptr<avm::IOperand> rhs) const
{
    avm::eOperandType type = (this->getType() > rhs->getType()) ? this->getType() : rhs->getType();

    std::string value = avm::Factory::convert(type, std::to_string(std::stoi(this->toString()) % std::stoi(rhs->toString())));

    return (avm::Factory::createOperand(type, value));
}
