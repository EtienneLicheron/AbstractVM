/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** dump
*/

#include "Core.hpp"

namespace Abstract {
    void Core::dump(std::string value) {
        (void)value;
        if (_stack.empty())
            throw Exception("Empty stack");
        for (auto it = _stack.rbegin(); it != _stack.rend(); it++) {
            std::cout << std::setprecision((*it)->toString().length()) << std::stof((*it)->toString()) << std::endl;
        }
    }
}