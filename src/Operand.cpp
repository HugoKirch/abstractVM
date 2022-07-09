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

    std::cout << "Type: " << type << std::endl;
    std::cout << "Value 1: " << std::stold(this->toString()) << this->getType() << std::endl;
    std::cout << "Value 2: " << std::stold(rhs->toString()) << rhs->getType() << std::endl;
    std::cout << "R old: " << std::to_string(std::stold(this->toString()) + std::stold(rhs->toString())) << std::stold(this->toString()) << std::endl;
    std::cout << "R: " << avm::Utils::setPrecision(std::stold(this->toString()) + std::stold(rhs->toString()), 15) << std::stold(this->toString()) << std::endl;
    


    std::string value = avm::Factory::convert(type, avm::Utils::setPrecision(std::stold(this->toString()) + std::stold(rhs->toString()), 15));
    std::cout << "value: " << value << std::endl;

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

    long double result = std::stold(this->toString()) / std::stold(rhs->toString());
    std::string v = avm::Utils::setPrecision(result, 20);
    std::string value = avm::Factory::convert(type, v);

    return (avm::Factory::createOperand(type, value));
}
std::shared_ptr<avm::IOperand> avm::Operand::operator%(const std::shared_ptr<avm::IOperand> rhs) const
{
    avm::eOperandType type = (this->getType() > rhs->getType()) ? this->getType() : rhs->getType();

    std::string value = avm::Factory::convert(type, std::to_string(std::stoi(this->toString()) % std::stoi(rhs->toString())));

    return (avm::Factory::createOperand(type, value));
}
