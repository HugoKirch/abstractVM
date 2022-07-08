/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Chipset
*/

#include "Chipset.hpp"

void avm::Chipset::addCommand(std::string str)
{
    std::string command;

    if (str.empty())
        return;
    command = avm::Utils::parseString(str, ';').front();
    if (command.empty())
        return;
    this->commands.push_back(command);
    
}

avm::Chipset::Chipset(std::string filename)
{
    std::string tmp;

    if (filename.length() == 0) {
        while (1) {
            getline(std::cin, tmp);
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
            throw avm::Error("file '" + std::string(filename) + "' not found");
        extension = std::filesystem::path(filename).extension();
        if (extension.empty())
            throw avm::Error("File hasn't extension");
        if (extension.generic_string().compare(".avm"))
            throw avm::Error("Bad file extension: '" + extension.generic_string() + "' instead of '.avm'");

        while (getline(file, tmp)) {
            this->addCommand(tmp);
        }
        file.close();
    }
    this->cpu = std::make_unique<avm::CPU>();
    this->initFonctions();
    this->execute();
}

avm::Chipset::~Chipset()
{
}

void avm::Chipset::initFonctions()  
{
    this->functions["push"] = &CPU::push;
    this->functions["pop"] = &CPU::pop;
    this->functions["clear"] = &CPU::clear;
    this->functions["dup"] = &CPU::dup;
    this->functions["swap"] = &CPU::swap;
    this->functions["dump"] = &CPU::dump;
    this->functions["assert"] = &CPU::assert;
    this->functions["add"] = &CPU::add;
    this->functions["sub"] = &CPU::sub;
    this->functions["mul"] = &CPU::mul;
    this->functions["div"] = &CPU::div;
    this->functions["mod"] = &CPU::mod;
    this->functions["load"] = &CPU::load;
    this->functions["store"] = &CPU::store;
    this->functions["print"] = &CPU::print;
    this->functions["exit"] = &CPU::exit;
}

std::vector<std::string> &avm::Chipset::getCommands()
{
    return (this->commands);
}

void avm::Chipset::execute()
{
    size_t line = 1;
    std::string function;

    for (std::string command : this->commands) {
        function = avm::Utils::parseString(command, ' ').front();
        if (!this->functions.count(function)) {
            throw avm::ExecuteError("command " + command + " not found", line);
        }
        try {
            ((*(this->cpu)).*(functions[function]))(command);
        }
        catch (avm::Error &e) {
            throw avm::ExecuteError(e.what(), line);
        }
        line++;
    }
}