/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** push
*/

#include "Core.hpp"

namespace Abstract {
    void Core::push(std::string value) {
        std::string newValue = value.substr(value.find_first_of('(') + 1);
        newValue.pop_back();
        eOperandType type = _typeMap[value.substr(0, value.find_first_of('('))];
        _stack.push_back(Factory::createOperand(type, newValue));
    }
}