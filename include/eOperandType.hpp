/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** eOperandType
*/

#pragma once

#include "CPU.hpp"

namespace avm {
    enum eOperandType {
        INT8,
        INT16,
        INT32,
        FLOAT,
        DOUBLE,
        BIGDECIMAL
    };
}