/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Operand
*/

#include "Operand.hpp"
#include "Factory.hpp"
#include "Utils.hpp"

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
    if (type == avm::BIGDECIMAL) {
        auto a = std::make_shared<avm::TBigDecimal>(this->toString());
        auto b = std::make_shared<avm::TBigDecimal>(rhs->toString());
        return (*a + b);
    }

    std::string value = avm::Factory::convert(type, avm::Utils::setPrecision(std::stold(this->toString()) + std::stold(rhs->toString()), 15));

    return (avm::Factory::createOperand(type, value));
}
std::shared_ptr<avm::IOperand> avm::Operand::operator-(const std::shared_ptr<avm::IOperand> rhs) const
{
    avm::eOperandType type = (this->getType() > rhs->getType()) ? this->getType() : rhs->getType();
    if (type == avm::BIGDECIMAL) {
        auto a = std::make_shared<avm::TBigDecimal>(this->toString());
        auto b = std::make_shared<avm::TBigDecimal>(rhs->toString());
        return (*a - b);
    }

    std::string value = avm::Factory::convert(type, std::to_string(std::stold(this->toString()) - std::stold(rhs->toString())));

    return (avm::Factory::createOperand(type, value));

}
std::shared_ptr<avm::IOperand> avm::Operand::operator*(const std::shared_ptr<avm::IOperand> rhs) const
{
    avm::eOperandType type = (this->getType() > rhs->getType()) ? this->getType() : rhs->getType();
    if (type == avm::BIGDECIMAL) {
        auto a = std::make_shared<avm::TBigDecimal>(this->toString());
        auto b = std::make_shared<avm::TBigDecimal>(rhs->toString());
        return (*a * b);
    }
    std::string value = avm::Factory::convert(type, std::to_string(std::stold(this->toString()) * std::stold(rhs->toString())));

    return (avm::Factory::createOperand(type, value));
}
std::shared_ptr<avm::IOperand> avm::Operand::operator/(const std::shared_ptr<avm::IOperand> rhs) const
{
    avm::eOperandType type = (this->getType() > rhs->getType()) ? this->getType() : rhs->getType();
    if (std::stold(rhs->toString()) == 0)
        throw Error("div by 0");

    long double result = std::stold(this->toString()) / std::stold(rhs->toString());
    std::string v = avm::Utils::setPrecision(result, 20);
    std::string value = avm::Factory::convert(type, v);


    return (avm::Factory::createOperand(type, value));
}
std::shared_ptr<avm::IOperand> avm::Operand::operator%(const std::shared_ptr<avm::IOperand> rhs) const
{
    avm::eOperandType type = (this->getType() > rhs->getType()) ? this->getType() : rhs->getType();

    if (std::stold(rhs->toString()) == 0)
        throw Error("modulo by 0");
    std::string value = avm::Factory::convert(type, std::to_string(std::stoi(this->toString()) % std::stoi(rhs->toString())));

    return (avm::Factory::createOperand(type, value));
}
