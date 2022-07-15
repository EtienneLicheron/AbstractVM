/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** load
*/

#include "Core.hpp"

namespace Abstract {
    void Core::load(std::string value) {
        std::string index = value.substr(value.find_first_of('(') + 1);
        index.pop_back();
        if (std::stoi(index) > 16)
            throw Exception("Register index out of range");
        std::list<IOperand *>::iterator it = _registers.begin();
        std::advance(it, std::stoi(index) - 1);
        if (*it == nullptr)
            throw Exception("Register is empty");
        _stack.push_back(Factory::createOperand((*it)->getType(), (*it)->toString()));
    }
}