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
   // std::shared_ptr<avm::IOperand> operand = nullptr;
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

}
void avm::CPU::sub()
{

}
void avm::CPU::mul()
{

}
void avm::CPU::div()
{

}
void avm::CPU::mod()
{

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
