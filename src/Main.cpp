/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** main
*/

#include "AVM.hpp"

int main(int argc, char **argv)
{
    try {
        std::unique_ptr<avm::AVM> avm = std::make_unique<avm::AVM>(argc, argv);
    }
    catch (avm::Error &e) {  
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}
