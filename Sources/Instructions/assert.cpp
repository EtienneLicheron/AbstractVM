/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** assert
*/

#include "Core.hpp"

namespace Abstract {
    void Core::assert(std::string value) {
        std::string newValue = value.substr(value.find_first_of('(') + 1);
        newValue.pop_back();
        eOperandType type = _typeMap[value.substr(0, value.find_first_of('('))];
        IOperand *tmp = Factory::createOperand(type, newValue);
        if (_stack.back()->getType() != tmp->getType() || _stack.back()->toString() != tmp->toString())
            throw Exception("Assertion failed");
    }
}