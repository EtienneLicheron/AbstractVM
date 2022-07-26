/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** pop
*/

#include "Core.hpp"

namespace Abstract {
    void Core::pop(std::string value) {
        (void)value;
        if (_stack.empty())
            throw Exception("Empty stack");
        _stack.pop_back();
    }
}