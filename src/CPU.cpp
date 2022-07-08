/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** CPU
*/

#include "CPU.hpp"

avm::CPU::CPU()
: memory()
{
    this->types = {
        "int8",
        "int16",
        "int32",
        "float",
        "double",
        "bigdecimal"
    };
}

avm::eOperandType avm::CPU::getType(std::string t)
{
    int i = 0;

    for (std::string str : this->types) {
        if (!t.compare(str))
            return ((avm::eOperandType)i);
        i++;
    }
    throw Error("Type " + t + " not found");
}

std::shared_ptr<avm::IOperand> avm::CPU::strToIOperand(std::string v)
{
    std::string value = parseValue(v);
    std::vector<std::string> values = avm::Utils::parseString(value, '(');
    if (values.size() != 2)
        throw Error("Invalid operand format: " + v);
    values.back().back() = '\0';
    std::shared_ptr<avm::IOperand> operand = avm::Factory::createOperand(getType(values.front()), values.back());
    return (operand);
}

std::string avm::CPU::parseValue(std::string v)
{
    std::vector<std::string> list = avm::Utils::parseString(v, ' ');
    if (list.size() < 2)
        throw Error("No parameter");
    else if (list.size() > 2)
        throw Error("Too many parameters");
    return (list.back());
}

void avm::CPU::push(std::string v)
{
    std::shared_ptr<avm::IOperand> operand = this->strToIOperand(v);
    this->memory.getStack().push(operand); 
}
void avm::CPU::pop()
{
    auto &stack = this->memory.getStack();
    if (stack.empty())
        throw Error("Stack is empty");
    stack.pop();
}
void avm::CPU::clear()
{
    for (size_t i = 0; i < this->memory.getStack().size(); i++)
    this->memory.getStack().pop();
}
void avm::CPU::dup()
{
    auto &stack = this->memory.getStack();
    if (stack.empty())
        throw Error("Stack is empty");
    auto a = stack.top();
    auto b = avm::Factory::createOperand(a->getType(), a->toString());
    stack.push(b);
}
void avm::CPU::swap()
{
    auto &stack = this->memory.getStack();
    if (stack.size() < 2)
        throw Error("stack must contains 2 values");
    std::shared_ptr<avm::IOperand> a = stack.top();
    stack.pop();
    std::shared_ptr<avm::IOperand> b  = stack.top();
    stack.pop();
    stack.push(a);
    stack.push(b);
}
void avm::CPU::dump()
{
    auto &stack = this->memory.getStack();
    if (stack.empty())
        return;
    auto x = stack.top();
    std::cout << x->toString() << std::endl;
    stack.pop();
    dump();
    stack.push(x);
}
void avm::CPU::assert(std::string v)
{
    std::shared_ptr<avm::IOperand> a = this->strToIOperand(v);
    auto b = this->memory.getStack().top();

    if (a->toString() != b->toString()) 
        throw Error("assert value failed: " + a->toString() + " != " + b->toString());
    if (a->getType() != b->getType()) 
        throw Error("assert type failed: " + this->types[a->getType()] + " != " + this->types[b->getType()]);
}
void avm::CPU::add()
{
    auto &stack = this->memory.getStack();
    if (stack.size() < 2)
        throw Error("stack must contains 2 values");
    std::shared_ptr<avm::IOperand> a = stack.top();
    stack.pop();
    std::shared_ptr<avm::IOperand> b = stack.top();
    stack.pop();
    std::shared_ptr<avm::IOperand> c = *b + a;
    stack.push(c);
}
void avm::CPU::sub()
{
    auto &stack = this->memory.getStack();
    if (stack.size() < 2)
        throw Error("stack must contains 2 values");
    std::shared_ptr<avm::IOperand> a = stack.top();
    stack.pop();
    std::shared_ptr<avm::IOperand> b = stack.top();
    stack.pop();
    std::shared_ptr<avm::IOperand> c = *b - a;
    stack.push(c);
}
void avm::CPU::mul()
{
    auto &stack = this->memory.getStack();
    if (stack.size() < 2)
        throw Error("stack must contains 2 values");
    std::shared_ptr<avm::IOperand> a = stack.top();
    stack.pop();
    std::shared_ptr<avm::IOperand> b = stack.top();
    stack.pop();
    std::shared_ptr<avm::IOperand> c = *b * a;
    stack.push(c);
}
void avm::CPU::div()
{
    auto &stack = this->memory.getStack();
    if (stack.size() < 2)
        throw Error("stack must contains 2 values");
    std::shared_ptr<avm::IOperand> a = stack.top();
    stack.pop();
    std::shared_ptr<avm::IOperand> b = stack.top();
    stack.pop();
    try {
        std::shared_ptr<avm::IOperand> c = *b / a;
        this->memory.getStack().push(c);
    }
    catch (std::exception &e) {
        throw Error(e.what());
    }
}
void avm::CPU::mod()
{
    auto &stack = this->memory.getStack();
    if (stack.size() < 2)
        throw Error("stack must contains 2 values");
    std::shared_ptr<avm::IOperand> a = stack.top();
    stack.pop();
    std::shared_ptr<avm::IOperand> b = stack.top();
    stack.pop();
    try {
        std::shared_ptr<avm::IOperand> c = *b % a;
        this->memory.getStack().push(c);
    }
    catch (std::exception &e) {
        throw Error(e.what());
    }
}
void avm::CPU::load(std::string v)
{
    auto &stack = this->memory.getStack();
    try {
        int i = std::stoi(parseValue(v));
        stack.push(this->memory.removeRegistry(i));
    }
    catch (std::exception &e){
        throw Error("invalid integer format " + v);
    }
}
void avm::CPU::store(std::string v)
{
    auto &stack = this->memory.getStack();
    if (stack.empty())
        throw Error("Stack is empty");
    try {
        int i = std::stoi(parseValue(v));
        this->memory.storeRegistry(i, stack.top());
        stack.pop();
    }
    catch (std::exception &e){
        throw Error("invalid integer format " + v);
    }
}
void avm::CPU::print()
{
    auto &stack = this->memory.getStack();
    if (stack.empty())
        throw Error("Stack is empty");
    auto a = stack.top();
    if (a->getType() != avm::INT8) 
        throw Error("assert type failed: " + this->types[a->getType()] + " != " + this->types[avm::INT8]);
    std::cout << (char)a->toString().front() << std::endl;
}
void avm::CPU::exit()
{

}

avm::CPU::~CPU()
{
}
