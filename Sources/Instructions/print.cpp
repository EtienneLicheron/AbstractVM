/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** print
*/

#include "Core.hpp"

namespace Abstract {
    void Core::print(std::string value) {
        (void)value;
        char ascii;
        std::string newValue = value.substr(value.find_first_of('(') + 1);
        newValue.pop_back();
        if (_stack.back()->getType() != Int8)
            throw Exception("Operand must be type of Int8");
        ascii = std::stoi(_stack.back()->toString());
        std::cout << ascii << std::endl;
    }
}