/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Operand
*/

#include "Operand.hpp"
#include "Factory.hpp"

std::shared_ptr<avm::IOperand> avm::Operand::operator+(const std::shared_ptr<avm::IOperand> rhs) const
{
    avm::eOperandType type = (this->getType() > rhs->getType()) ? this->getType() : rhs->getType();
/*     if (type == avm::BIGDECIMAL) {
        auto a = std::make_shared<avm::TBigDecimal>(this->toString());
        auto b = std::make_shared<avm::TBigDecimal>(rhs->toString());
        return (*a + b);
    }
    */

    std::string value = this->data->getFunction()(avm::Utils::setPrecision(std::stold(this->toString()) + std::stold(rhs->toString()), 15));

    return (avm::Factory::createOperand(type, value));
}
std::shared_ptr<avm::IOperand> avm::Operand::operator-(const std::shared_ptr<avm::IOperand> rhs) const
{
    avm::eOperandType type = (this->getType() > rhs->getType()) ? this->getType() : rhs->getType();
/*    if (type == avm::BIGDECIMAL) {
        auto a = std::make_shared<avm::TBigDecimal>(this->toString());
        auto b = std::make_shared<avm::TBigDecimal>(rhs->toString());
        return (*a - b);
    }*/

    std::string value = this->data->getFunction()(std::to_string(std::stold(this->toString()) - std::stold(rhs->toString())));

    return (avm::Factory::createOperand(type, value));

}
std::shared_ptr<avm::IOperand> avm::Operand::operator*(const std::shared_ptr<avm::IOperand> rhs) const
{
    avm::eOperandType type = (this->getType() > rhs->getType()) ? this->getType() : rhs->getType();
/*       if (type == avm::BIGDECIMAL) {
        auto a = std::make_shared<avm::TBigDecimal>(this->toString());
        auto b = std::make_shared<avm::TBigDecimal>(rhs->toString());
        return (*a * b);
    }*/
    std::string value = this->data->getFunction()(std::to_string(std::stold(this->toString()) * std::stold(rhs->toString())));

    return (avm::Factory::createOperand(type, value));
}
std::shared_ptr<avm::IOperand> avm::Operand::operator/(const std::shared_ptr<avm::IOperand> rhs) const
{
    avm::eOperandType type = (this->getType() > rhs->getType()) ? this->getType() : rhs->getType();
    if (std::stold(rhs->toString()) == 0)
        throw Error("div by 0");

    long double result = std::stold(this->toString()) / std::stold(rhs->toString());
    std::string v = avm::Utils::setPrecision(result, 20);
    std::string value = this->data->getFunction()(v);


    return (avm::Factory::createOperand(type, value));
}
std::shared_ptr<avm::IOperand> avm::Operand::operator%(const std::shared_ptr<avm::IOperand> rhs) const
{
    avm::eOperandType type = (this->getType() > rhs->getType()) ? this->getType() : rhs->getType();

    if (std::stold(rhs->toString()) == 0)
        throw Error("modulo by 0");
    std::string value = this->data->getFunction()(std::to_string(std::stoi(this->toString()) % std::stoi(rhs->toString())));

    return (avm::Factory::createOperand(type, value));
}