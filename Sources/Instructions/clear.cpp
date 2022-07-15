/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** clear
*/

#include "Core.hpp"

namespace Abstract {
    void Core::clear(std::string value) {
        (void)value;
        if (_stack.empty())
            throw Exception("Empty stack");
        for (auto it = _stack.begin(); it != _stack.end(); it++)
            delete *it;
        _stack.clear();
    }
}