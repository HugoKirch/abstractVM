/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** Error
*/

#pragma once

#include <string>
#include <ostream>
#include <exception>

class Error : public std::exception
{
    public:
        Error(std::string const &message);
        const std::string what();

    private:
        std::string message;
};