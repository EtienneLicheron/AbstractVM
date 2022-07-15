/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** add
*/

#include "Core.hpp"

namespace Abstract {
    void Core::add(std::string value) {
        (void)value;
        if (_stack.size() < 2)
            throw Exception("Not enough elements (at least two)");
        IOperand *first = _stack.back();
        _stack.pop_back();
        IOperand *second = _stack.back();
        _stack.pop_back();
        // if (first->getType() > second->getType())
            // _stack.push_back(Factory::createOperand(first->getType(), first->operator+(&second)->toString()));
    }
}