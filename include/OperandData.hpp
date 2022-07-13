/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** OperandData
*/

#pragma once

#include "IOperand.hpp"
#include <memory>
#include <any>

namespace avm {

    struct AbstractField{
        virtual ~AbstractField() = 0;
    };

    template <typename T>
    class OperandData : public avm::AbstractField {
        public:
            OperandData(avm::eOperandType type, std::string (*f)(const std::string &value, T *ptr), const std::string &name, int precision)
            : type(type), f(f), name(name), precision(precision)
            {
            }

            ~OperandData()
            {
            }

            inline avm::eOperandType getType() const
            {
                return (this->type);
            }

            inline std::shared_ptr<avm::IOperand> (*getFunction())(const std::string &) const
            {
                return (this->f);
            }

            inline const std::string &getName() const
            {
                return (this->name);
            }


        private:
            std::string (*f)(const std::string &value, T *ptr);
            avm::eOperandType type;
            const std::string &name;
            int precision;
    };
}