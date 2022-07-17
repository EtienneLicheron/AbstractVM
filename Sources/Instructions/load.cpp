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
        if (std::stoi(index) > 15 || std::stoi(index) < 0)
            throw Exception("Register index out of range");
        auto it = std::next(_registers.begin(), std::stoi(index));
        IOperand *tmp = Factory::createOperand((*it)->getType(), (*it)->toString());
        _stack.push_back(tmp);
    }
}