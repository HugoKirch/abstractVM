/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Memory
*/

#include "Memory.hpp"

avm::Memory::Memory()
{
    for (size_t i = 0; i < (size_t)16; i++)
        this->registry[i] = nullptr;
}

avm::Memory::~Memory()
{
}

std::shared_ptr<std::stack<std::shared_ptr<avm::IOperand>>> avm::Memory::getStack()
{
    return (this->stack);
}

std::shared_ptr<avm::IOperand> avm::Memory::removeRegistry(int i)
{
    std::shared_ptr<avm::IOperand> operand;
    if (i < 0 || i > 15)
        throw avm::Error("Index out of bounds from registry: "  + i);
    if (this->registry[i] == nullptr)
        throw avm::Error("Null value in registry");
    operand = this->registry[i];
    this->registry[i] = nullptr;
    return (operand);
    
}

void avm::Memory::storeRegistry(int i, std::shared_ptr<IOperand> v)
{
    if (i < 0 || i > 15)
        throw avm::Error("Index out of bounds from registry: "  + i);
    this->registry[i] = v;
}