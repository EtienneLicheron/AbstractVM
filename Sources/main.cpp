/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** main
*/

#include "Core.hpp"

int main(int ac, char **av)
{
    Abstract::Core core;

    try {
        core.checkArguments(ac, av);
        core.run();
    }
    catch (std::exception &e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
    }
    return 0;
}