/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Factory
*/

#pragma once

#include "IOperand.hpp"
#include "TBigDecimal.hpp"
#include "OperandData.hpp"

#include <string>
#include <array>
#include <memory>
#include <any>

namespace avm {
    class Factory {
        public:
            template <typename T>
            static std::shared_ptr<avm::IOperand> createOperand(avm::eOperandType type, const std::string &value);
        private:
            static std::shared_ptr<avm::Factory> instance;
            Factory();
            ~Factory();
            std::array<std::shared_ptr<avm::AbstractField>, 6> operandsData;
            static std::array<std::shared_ptr<IOperand> (*)(const std::string &), 6> functions;
            static std::array<std::string (*)(const std::string &), 6> fconvert;
            static std::string stoi(const std::string &value, int *ptr = nullptr);
            static std::string stof(const std::string &value, float *ptr = nullptr);
            static std::string stod(const std::string &value, double *ptr = nullptr);
            static std::string stold(const std::string &value, long double *ptr = nullptr);
    };
}

template <typename T>
std::shared_ptr<avm::IOperand> avm::Factory::createOperand(avm::eOperandType type, const std::string &value)
{
    auto function = avm::Factory::functions.at(type);
    
    std::string v = avm::Utils::removeTrailingZero(value);

    return (std::make_shared<avm::Operand<T>>(v, avm::Factory::instance->operandsData.at(type)));
}
