/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** dup
*/

#include "Core.hpp"

namespace Abstract {
    void Core::dup(std::string value) {
        (void)value;
        if (_stack.empty())
            throw Exception("Empty stack");
        _stack.push_back(Factory::createOperand(_stack.back()->getType(), _stack.back()->toString()));
    }
}