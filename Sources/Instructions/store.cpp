/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** store
*/

#include "Core.hpp"

namespace Abstract {
    void Core::store(std::string value) {
        if (_registers.size() == 16)
            throw Exception("Too many registers");
        std::string index = value.substr(value.find_first_of('(') + 1);
        index.pop_back();
        if (std::stoi(index) > 15 || std::stoi(index) < 0)
            throw Exception("Register index out of range");
        IOperand *it = Factory::createOperand(_stack.back()->getType(), _stack.back()->toString());
        _registers[std::stoi(index)] = it;
        _stack.pop_back();
    }
}