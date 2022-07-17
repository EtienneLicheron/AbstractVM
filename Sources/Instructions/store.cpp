/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** store
*/

#include "Core.hpp"

namespace Abstract {
    void Core::store(std::string value) {
        std::string index = value.substr(value.find_first_of('(') + 1);
        index.pop_back();

        if (std::stoi(index) > 15 || std::stoi(index) < 0)
            throw Exception("Register index out of range");

        auto it = std::next(_registers.begin(), std::stoi(index));

        if (*it != nullptr) {
            IOperand *tmp = *it;
            (*it) = nullptr;
            delete tmp;
        }

        if (_stack.empty())
            throw Exception("Empty stack");
        _registers.insert(it, Factory::createOperand(_stack.back()->getType(), _stack.back()->toString()));
        IOperand *toDelete = _stack.back();
        _stack.pop_back();
        delete toDelete;
    }
}