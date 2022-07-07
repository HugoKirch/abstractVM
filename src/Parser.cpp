/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Parser
*/

#include "Parser.hpp"


std::vector<std::string> avm::Parser::parseString(std::string line, char separator)
{

    std::vector<std::string> result;
    std::istringstream iss(line);
    std::string tmp;

    while(std::getline(iss, tmp, separator)) {
        result.push_back(tmp);
    }
    return (result);
}

void avm::Parser::addCommand(std::string str)
{
    std::string command;

    if (str.empty())
        return;
    command = this->parseString(str, ';').front();
    if (command.empty())
        return;
    this->commands.push_back(command);
    
}

avm::Parser::Parser(std::string filename)
{
    std::string tmp;

    if (filename.length() == 0) {
        while (1) {
            std::cin >> tmp;
            if (!tmp.compare(";;"))
                break;
            this->addCommand(tmp);
        }
    }
    else {
        std::ifstream file;
        std::filesystem::path extension;

        file = std::ifstream(filename);
        if (!file)
            throw Error("file '" + std::string(filename) + "' not found");
        extension = std::filesystem::path(filename).extension();
        if (extension.empty())
            throw Error("File hasn't extension");
        if (extension.generic_string().compare(".avm"))
            throw Error("Bad file extension: '" + extension.generic_string() + "' instead of '.avm'");

        while (getline(file, tmp)) {
            this->addCommand(tmp);
        }
        file.close();
    }
}

avm::Parser::~Parser()
{
}

std::vector<std::string> &avm::Parser::getCommands()
{
    return (this->commands);
}
