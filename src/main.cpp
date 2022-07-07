/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** main
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <string.h>
#include <fstream>
#include "Error.hpp"

std::vector<std::string> getCommands(std::string filename)
{
    std::vector<std::string> list;
    std::string tmp;

    if (filename.length() == 0) {
        while (1) {
            std::cin >> tmp;
            if (!tmp.compare(";;"))
                break;
            tmp.clear();
        }
    }
    else {
        std::ifstream input_file(filename);
        if (!input_file.is_open()) {
            throw Error("Could not open the file - '" + filename + "'");
        }

        while (getline(input_file, tmp)) {
            list.push_back(tmp);
        }
        input_file.close();
    }
    return (list);
}

bool errorHandling(int argc, char **argv)
{
    switch (argc) {
        case 1:
            std::cout << "1" << std::endl;
            break;
        case 2:
            if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
                std::cout << "Usage: ./abstractVM [file.avm]" << std::endl;
            else {
                
            }
            break;
        default:
            std::cerr << "Error: too many arguments" << std::endl;
            return (false);
    }
    return (true);
}

int main(int argc, char **argv)
{
    if (!errorHandling(argc, argv))
        return (84);
    return (0);
}