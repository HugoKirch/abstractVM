/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** CPU
*/

#include "CPU.hpp"

avm::CPU::CPU()
{
}

std::string avm::CPU::parseValue(std::string v)
{
    std::vector<std::string> list = avm::Utils::parseString(v, ' ');
    std::cout << "size: " << list.size() << std::endl;
    if (list.size() < 2)
        throw Error("No parameter");
    else if (list.size() > 2)
        throw Error("Too many parameters");
    return (list.at(1));
}

void avm::CPU::push(std::string v)
{
   // std::shared_ptr<avm::Operand> operand = nullptr;
  //  this->memory->getStack()->push(operand);
    std::cout << parseValue(v) << std::endl;
}
void avm::CPU::pop()
{
    std::cout << "popit" << std::endl;
}
void avm::CPU::clear()
{

}
void avm::CPU::dup()
{

}
void avm::CPU::swap()
{

}
void avm::CPU::dump()
{

}
void avm::CPU::assert(std::string v)
{
    (void)v;
}
void avm::CPU::add()
{
    std::shared_ptr<avm::IOperand> a = this->memory->getStack()->top();
    this->memory->getStack()->pop();
    std::shared_ptr<avm::IOperand> b = this->memory->getStack()->top();
    this->memory->getStack()->pop();
    std::shared_ptr<avm::IOperand> c = *a + b;
    this->memory->getStack()->push(c);
}
void avm::CPU::sub()
{
    std::shared_ptr<avm::IOperand> a = this->memory->getStack()->top();
    this->memory->getStack()->pop();
    std::shared_ptr<avm::IOperand> b = this->memory->getStack()->top();
    this->memory->getStack()->pop();
    std::shared_ptr<avm::IOperand> c = *a - b;
    this->memory->getStack()->push(c);
}
void avm::CPU::mul()
{
    std::shared_ptr<avm::IOperand> a = this->memory->getStack()->top();
    this->memory->getStack()->pop();
    std::shared_ptr<avm::IOperand> b = this->memory->getStack()->top();
    this->memory->getStack()->pop();
    std::shared_ptr<avm::IOperand> c = *a * b;
    this->memory->getStack()->push(c);
}
void avm::CPU::div()
{
    std::shared_ptr<avm::IOperand> a = this->memory->getStack()->top();
    this->memory->getStack()->pop();
    std::shared_ptr<avm::IOperand> b = this->memory->getStack()->top();
    this->memory->getStack()->pop();
    try {
        std::shared_ptr<avm::IOperand> c = *a / b;
        this->memory->getStack()->push(c);
    }
    catch (std::exception e) {
        throw Error(e.what());
    }
}
void avm::CPU::mod()
{
    std::shared_ptr<avm::IOperand> a = this->memory->getStack()->top();
    this->memory->getStack()->pop();
    std::shared_ptr<avm::IOperand> b = this->memory->getStack()->top();
    this->memory->getStack()->pop();
    try {
        std::shared_ptr<avm::IOperand> c = *a % b;
        this->memory->getStack()->push(c);
    }
    catch (std::exception e) {
        throw Error(e.what());
    }
}
void avm::CPU::load(std::string v)
{
    (void)v;
}
void avm::CPU::store(std::string v)
{
    (void)v;
}
void avm::CPU::print()
{

}
void avm::CPU::exit()
{

}

avm::CPU::~CPU()
{
}
