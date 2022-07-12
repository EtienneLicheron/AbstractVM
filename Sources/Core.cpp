/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** Core
*/

#include "Core.hpp"

namespace Abstract {
    Core::Core() : _fileName("")
    {
    }

    Core::~Core()
    {
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
        _fileName = fileName;
        return;
    }

    void Core::parseLine(std::string line)
    {
        
    }

    void Core::parseFile(std::istream& in)
    {
        std::string line;
        std::regex commentary("^(;.*)$");
        std::regex commands("(((push|assert|load|store)\\s*((int8|int16|int32)\\([-]?[0-9]+\\)|(float|double|bigdecimal)\\([-]?[0-9]+[.]?[0-9]*\\)))|(pop|dump|clear|dup|swap|add|sub|mul|div|mod|print)\\s*)|exit\\s*");

        while (std::getline(in, line)) {
            if (std::regex_match(line, commentary))
                continue;
            else if (std::regex_match(line, commands)) {
                _instructions.push_back(line);
                continue;
            }
            throw Exception("Invalid instruction or syntax");
        }
    }

    void Core::compute()
    {
        for (auto &instruction : _instructions) {
            std::cout << instruction << std::endl;
        }
    }

    void Core::run()
    {
        if (_fileName == "")
            compute();
        else {
            std::ifstream file(_fileName.c_str());
            parseFile(file);
            compute();
        }
    }
}