/*
** EPITECH PROJECT, 2022
** Parser
** File description:
** Error
*/

#include "Error.hpp"
#include <iostream>
#include <sstream>

const std::string avm::Error::what()
{
    return this->message;
}

avm::Error::Error(std::string const &message)
{
    std::stringstream ss;

    ss << "\033[1;31mError: " << message << "\033[0m";
    this->message = ss.str();
}

avm::ExecuteError::ExecuteError(std::string const &message, size_t line)
: Error(message)
{
    std::stringstream ss;

    ss << "\033[1;31mLine " << line << " " << message << "\033[0m";
    this->message = ss.str();
}