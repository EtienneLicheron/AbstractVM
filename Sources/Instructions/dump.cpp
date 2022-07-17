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
            fesetround(FE_UPWARD);
            if ((*it)->getType() == Float)
                std::cout << std::fixed << std::setprecision(7) << (*it)->toString() << std::endl;
            else if ((*it)->getType() == Double)
                std::cout << std::fixed << std::setprecision(15) << (*it)->toString() << std::endl;
            else if ((*it)->getType() == BigDecimal)
                std::cout << std::fixed << std::setprecision(200) << (*it)->toString() << std::endl;
            else
                std::cout << (*it)->toString() << std::endl;
        }
    }
}