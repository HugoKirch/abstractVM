/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Main
*/

#include "Main.hpp"

avm::Main::Main(int argc, char **argv)
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

avm::Main::~Main()
{
}

std::shared_ptr<avm::Parser> avm::Main::getParser()
{
    return (this->parser);
}

int main(int argc, char **argv)
{
    try {
        std::unique_ptr<avm::Main> main = std::make_unique<avm::Main>(argc, argv);
        for (std::string command : main->getParser()->getCommands()) {
            std::cout << command << std::endl;
        }
    }
    catch (Error &e) {  
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}
