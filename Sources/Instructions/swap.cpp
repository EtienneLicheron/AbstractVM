/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** swap
*/

#include "Core.hpp"

namespace Abstract {
    void Core::swap(std::string value) {
        (void)value;
        if (_stack.size() < 2)
            throw Exception("Not enough elements in stack");
        IOperand *first = _stack.back();
        _stack.pop_back();
        IOperand *second = _stack.back();
        _stack.pop_back();
        _stack.push_back(first);
        _stack.push_back(second);
    }
}