/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** div
*/

#include "Core.hpp"

namespace Abstract {
    void Core::div(std::string value) {
        (void)value;
        if (_stack.size() < 2)
            throw Exception("Not enough elements (at least two)");
        IOperand *first = _stack.back();
        _stack.pop_back();
        IOperand *second = _stack.back();
        _stack.pop_back();
        if (second->toString() == "0")
            throw Exception("Division by zero");
        _stack.push_back(first->operator/(*second));
        delete(first);
        delete(second);
    }
}