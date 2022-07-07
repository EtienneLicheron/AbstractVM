/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** Core
*/

#include "Core.hpp"

namespace Abstract {
    Core::Core()
    {
        _isRunning = true;
        _stream = &std::cin;
    }

    Core::~Core()
    {
    }

    void Core::setStream(std::istream *stream)
    {
        _stream = stream;
    }

    void Core::checkArguments(int ac, char **av)
    {
        std::string fileName;

        if (ac == 1) {
            return;
        }
        if (ac > 2)
            throw Abstract::Exception("too much arguments");
        fileName = std::string(av[1]);
        if (fileName.length() <= 4 || fileName.substr(fileName.size() - 4, 4) != ".avm")
            throw Abstract::Exception("file must be a .avm");
        std::ifstream file(fileName.c_str());
        if (!file.is_open())
            throw Abstract::Exception("file not found");
        setStream(&file);
        return;
    }

    void Core::run()
    {
        for (std::string line; std::getline(*_stream, line);) {
            std::cout << line << std::endl;
        }
    }
}