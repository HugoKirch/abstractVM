/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Chipset
*/

#pragma once

#include "Error.hpp"
#include "CPU.hpp"
#include "Utils.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>
#include <map>

namespace avm {
    class Chipset {
        public:
            Chipset(std::string filename = "");
            ~Chipset();
            std::vector<std::string> &getCommands();
            void addCommand(std::string str);
            void execute();
            void initFonctions();

        private:
            std::map<std::string, void (CPU::*) (std::string)> functions;
            std::vector<std::string> commands;
            std::unique_ptr<avm::CPU> cpu;
        
    };
}
