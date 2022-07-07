/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** Chipset
*/

#pragma once

#include <vector>
#include <string>

class Chipset {
    public:
        Chipset(stf::vector<std::string> commands);
        ~Chipset();

    private:
        std::vector<std::string> commands;
};
