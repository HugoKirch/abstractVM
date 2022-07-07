/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** AVM
*/

#pragma once

#include "Error.hpp"

#include <string>
#include <vector>
#include <Chipset.hpp>
#include <iostream>
#include <cstring>
#include <fstream>
#include <memory>

namespace avm {
    class AVM {
        public:
            AVM(int argc, char **argv);
            ~AVM();
            std::shared_ptr<avm::Chipset> getParser();

        private:
            std::shared_ptr<avm::Chipset> parser;
    };
}