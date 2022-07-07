/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Parser
*/

#pragma once

#include "Error.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>

namespace avm {
    class Parser {
        public:
            Parser(std::string filename = "");
            ~Parser();
            std::vector<std::string> &getCommands();
            std::vector<std::string> parseString(std::string line, char separator);
            void addCommand(std::string str);

        private:
            std::vector<std::string> commands;
    };
}
