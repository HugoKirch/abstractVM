/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** AVM
*/

#include "AVM.hpp"

avm::AVM::AVM(int argc, char **argv)
{
    switch (argc) {
        case 1:
            this->parser = std::make_unique<avm::Parser>();
            break;
        case 2:
            if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
                std::cout << "Usage: ./abstractVM [file.avm]" << std::endl;
            else {
                this->parser = std::make_unique<avm::Parser>(argv[1]);
            }
            break;
        default:
            throw Error("too many arguments");
    }
}

avm::AVM::~AVM()
{
}

std::shared_ptr<avm::Parser> avm::AVM::getParser()
{
    return (this->parser);
}