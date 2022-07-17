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

        auto it = std::next(_registers.begin(), std::stoi(index));

        if (*it != nullptr) {
            delete *it;
        }

        if (_stack.empty())
            throw Exception("Empty stack");
        _registers.insert(it, Factory::createOperand(_stack.back()->getType(), _stack.back()->toString()));
        IOperand *toDelete = _stack.back();
        _stack.pop_back();
        delete toDelete;
    }
}