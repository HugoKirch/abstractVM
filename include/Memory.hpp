/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Memory
*/

#pragma once

#include <vector>
#include <stack>
#include <memory>
#include "IOperand.hpp"
#include "Error.hpp"

namespace avm {
    class Memory {
        public:
            Memory();
            ~Memory();
            std::shared_ptr<avm::IOperand> removeRegistry(int i);
            void storeRegistry(int i, std::shared_ptr<IOperand> v);
            std::shared_ptr<std::stack<std::shared_ptr<avm::IOperand>>> getStack();

        private:
            std::shared_ptr<std::stack<std::shared_ptr<avm::IOperand>>> stack;
            std::shared_ptr<avm::IOperand> registry[16];
    };
}
