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
        std::list<IOperand *> _stack = {};
        std::list<IOperand *> _registers = {};
        _isRunning = true;
        _fileName = "";
        _mapFunctions["add"] = &Core::add;
        _mapFunctions["assert"] = &Core::assert;
        _mapFunctions["clear"] = &Core::clear;
        _mapFunctions["div"] = &Core::div;
        _mapFunctions["dump"] = &Core::dump;
        _mapFunctions["dup"] = &Core::dup;
        _mapFunctions["exit"] = &Core::exit;
        _mapFunctions["load"] = &Core::load;
        _mapFunctions["mod"] = &Core::mod;
        _mapFunctions["mul"] = &Core::mul;
        _mapFunctions["pop"] = &Core::pop;
        _mapFunctions["print"] = &Core::print;
        _mapFunctions["push"] = &Core::push;
        _mapFunctions["store"] = &Core::store;
        _mapFunctions["sub"] = &Core::sub;
        _mapFunctions["swap"] = &Core::swap;
        _mapFunctions[";;"] = &Core::exit;
    }

    Core::~Core()
    {
        if (!_stack.empty()) {
            for (auto it = _stack.begin(); it != _stack.end(); it++)
                delete *it;
        }
        if (!_registers.empty()) {
            for (auto it = _registers.begin(); it != _registers.end(); it++)
                delete *it;
        }
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
        std::string command = line.substr(0, line.find(" "));
        std::string value;

        if (line.find_last_of(" ") >= std::string::npos)
            value = "";
        else
            value = line.substr(line.find_last_of(" ") + 1);
        _commands.push_back(std::make_pair(command, value));
    }

    void Core::parseFile(std::istream& in)
    {
        std::string line;
        std::regex commentary("^(;.*)$");
        std::regex commands("(((push|assert|load|store)\\s*((int8|int16|int32)\\([-]?[0-9]+\\)(\\s*$|;.*.|;)|(float|double|bigdecimal)\\([-]?[0-9]+[.]?[0-9]*\\)(\\s*$|;.*.|;)))|(pop|dump|clear|dup|swap|add|sub|mul|div|mod|print)($|\\s*$|\\s*;.*))|exit\\s*");

        while (std::getline(in, line)) {
            if (std::regex_match(line, commentary) || line.empty())
                continue;
            else if (std::regex_match(line, commands)) {
                parseLine(line);
                continue;
            }
            throw Exception("Invalid instruction or syntax");
        }
    }

    void Core::compute()
    {
        for (auto &commands : _commands) {
            for (auto const& x : _mapFunctions) {
                if (commands.first == x.first)
                    (this->*x.second)(commands.second);
            }
        }
    }

    void Core::computeEntry(std::istream& in)
    {
        std::string line;
        std::regex commands("(((push|assert|load|store)\\s*((int8|int16|int32)\\([-]?[0-9]+\\)(\\s*$|;.*.|;)|(float|double|bigdecimal)\\([-]?[0-9]+[.]?[0-9]*\\)(\\s*$|;.*.|;)))|(pop|dump|clear|dup|swap|add|sub|mul|div|mod|print)($|\\s*$|\\s*;.*))|;;\\s*|exit\\s*");
        std::string tmp;

        while (std::getline(in, line)) {
            tmp = line;
            tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());
            if (tmp == ";;")
                break;
            if (std::regex_match(line, commands)) {
                parseLine(line);
                continue;
            }
            // else if (line == "exit")
            //     continue;
            // else
                throw Exception("Invalid instruction or syntax");
        }
        compute();
    }

    void Core::run()
    {
        if (_fileName == "") {
            computeEntry(std::cin);
        }
        else {
            std::ifstream file(_fileName.c_str());
            parseFile(file);
            file.close();
            if (_commands.back().first != "exit")
                throw Exception("File must end with exit");
            compute();
        }
    }
}