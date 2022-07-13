/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Factory
*/

#include "Factory.hpp"
#include "Utils.hpp"
#include <sstream>

std::shared_ptr<avm::Factory> avm::Factory::instance = {
    std::make_shared<avm::Factory>()
};

avm::Factory::Factory()
{
    this->operandsData = {
        std::make_shared<avm::OperandData<char>>(avm::eOperandType::INT8, &avm::Factory::stoi, "int8"),
        std::make_shared<avm::OperandData<short>>(avm::eOperandType::INT16, &avm::Factory::stoi, "int16"),
        std::make_shared<avm::OperandData<int>>(avm::eOperandType::INT32, &avm::Factory::stoi, "int32"),
        std::make_shared<avm::OperandData<float>>(avm::eOperandType::FLOAT, &avm::Factory::stof, "float"),
        std::make_shared<avm::OperandData<double>>(avm::eOperandType::DOUBLE, &avm::Factory::stod, "double"),
        std::make_shared<avm::OperandData<long double>>(avm::eOperandType::BIGDECIMAL, &avm::Factory::stold, "bigdecimal")
    };
}

std::string avm::Factory::stoi(const std::string &value, int *ptr)
{
    if (ptr != nullptr)
        *ptr = std::stoi(value);
    return (std::to_string(std::stoi(value)));
}
std::string avm::Factory::stof(const std::string &value, float *ptr)
{
    if (ptr != nullptr)
        *ptr = std::stof(value);
    std::ostringstream out;
    out.precision(7);
    out << std::fixed << std::stof(value);
    return (out.str());
}
std::string avm::Factory::stod(const std::string &value, double *ptr)
{
    if (ptr != nullptr)
        *ptr = std::stod(value);
    std::ostringstream out;
    out.precision(15);
    out << std::fixed << std::stod(value);
    return (out.str());
}
std::string avm::Factory::stold(const std::string &value, long double *ptr)
{
    if (ptr != nullptr)
        *ptr = std::stold(value);
    std::ostringstream out;
    out.precision(20);
    out << std::fixed << std::stold(value);
    return (out.str());
}