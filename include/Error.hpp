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


namespace avm {
    class Error : public std::exception
    {
        public:
            Error(std::string const &message);
            const std::string what();

        protected:
            std::string message;
    };

    class ExecuteError : public Error
    {
        public:
            ExecuteError(std::string const &message, size_t line);
    };
}