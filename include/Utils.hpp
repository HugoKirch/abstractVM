/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Utils
*/

#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>


namespace avm {
    class Utils {
        public:
            static std::vector<std::string> parseString(std::string line, char separator);
            static std::string removeTrailingZero(std::string str);
    };
}