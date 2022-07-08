/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Utils
*/

#include "Utils.hpp"

std::vector<std::string> avm::Utils::parseString(std::string line, char separator)
{

    std::vector<std::string> result;
    std::istringstream iss(line);
    std::string tmp;

    while(std::getline(iss, tmp, separator)) {
        if (!tmp.empty())
            result.push_back(tmp);
    }
    return (result);
}
