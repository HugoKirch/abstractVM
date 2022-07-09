/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Factory
*/

#pragma once

#include "IOperand.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "BigDecimal.hpp"

#include <string>
#include <array>
#include <memory>

namespace avm {
    class Factory {
        public:
            static std::string convert(eOperandType, const std::string &value);
            static std::shared_ptr<IOperand> createOperand(eOperandType type, const std::string &value);
        private:
            static std::array<std::shared_ptr<IOperand> (*)(const std::string &), 6> functions;
            static std::array<std::string (*)(const std::string &), 6> fconvert;
            static std::shared_ptr<IOperand> createInt8(const std::string &value);
            static std::shared_ptr<IOperand> createInt16(const std::string &value);
            static std::shared_ptr<IOperand> createInt32(const std::string &value);
            static std::shared_ptr<IOperand> createFloat(const std::string &value);
            static std::shared_ptr<IOperand> createDouble(const std::string &value);
            static std::shared_ptr<IOperand> createBigDecimal(const std::string &value);
            static std::string stoi(const std::string &value);
            static std::string stof(const std::string &value);
            static std::string stod(const std::string &value);
            static std::string stold(const std::string &value);
    };
}
