/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** exit
*/

#include "Core.hpp"

namespace Abstract {
    void Core::exit(std::string value) {
        (void)value;
        _isRunning = false;
    }
}