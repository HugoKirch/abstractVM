/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Main
*/

#pragma once

#include "Error.hpp"

#include <string>
#include <vector>
#include <Parser.hpp>
#include <iostream>
#include <cstring>
#include <fstream>
#include <memory>

namespace avm {
    class Main {
        public:
            Main(int argc, char **argv);
            ~Main();
            std::shared_ptr<avm::Parser> getParser();

        private:
            std::shared_ptr<avm::Parser> parser;
    };
}