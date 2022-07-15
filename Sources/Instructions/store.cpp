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
        _registers.assign(std::stoi(index), _stack.back());
        _stack.pop_back();
    }
}