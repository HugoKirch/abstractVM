/*
** EPITECH PROJECT, 2022
** Parser
** File description:
** Error
*/

#include "Error.hpp"
#include <iostream>
#include <sstream>

const std::string Error::what()
{
    std::stringstream ss;

    ss << "\033[1;31mError: " << this->message << "\033[0m";
    return (ss.str());
}

Error::Error(std::string const &message)
: message(message)
{

}