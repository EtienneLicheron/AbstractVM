/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** sub
*/

#include "Core.hpp"

namespace Abstract {
    void Core::sub(std::string value) {
        (void)value;
        if (_stack.size() < 2)
            throw Exception("Not enough elements (at least two)");
        IOperand *second = _stack.back();
        _stack.pop_back();
        IOperand *first = _stack.back();
        _stack.pop_back();
        if (second->getType() > first->getType())
            _stack.push_back(second->operator-(*first));
        else
            _stack.push_back(first->operator-(*second));
        delete(first);
        delete(second);
    }
}