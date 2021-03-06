/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** CPU
*/

#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include <array>
#include "Utils.hpp"
#include "Memory.hpp"
#include "Operand.hpp"
#include "Factory.hpp"

namespace avm {
    class CPU {
        public:
            CPU();
            ~CPU();
            std::shared_ptr<avm::IOperand> strToIOperand(std::string v);
            avm::eOperandType getType(std::string t);
            std::string parseValue(std::string v);
            void push(std::string v);
            void pop(std::string v) {(void)v;pop();}
            void pop();
            void clear(std::string v) {(void)v;clear();}
            void clear();
            void dup(std::string v) {(void)v;dup();}
            void dup();
            void swap(std::string v) {(void)v;swap();}
            void swap();
            void dump(std::string v){(void)v;dump();}
            void dump();
            void assert(std::string v);
            void add(std::string v) {(void)v;add();}
            void add();
            void sub(std::string v) {(void)v;sub();}
            void sub();
            void mul(std::string v) {(void)v;mul();}
            void mul();
            void div(std::string v) {(void)v;div();}
            void div();
            void mod(std::string v) {(void)v;mod();}
            void mod();
            void load(std::string v);
            void store(std::string v);
            void print(std::string v) {(void)v;print();}
            void print();
            void exit(std::string v) {(void)v;exit();}
            void exit();

        private:
            avm::Memory memory;
            std::array<std::string, 6> types;
    };
}
