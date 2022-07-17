/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_
    #include <iostream>
    #include <string>
    #include <vector>
    #include <unistd.h>
    #include <fstream>
    #include <regex>
    #include <iostream>
    #include <sstream>
    #include <iterator>
    #include <cmath>
    #include <cfenv>
    #include <list>
    #include <algorithm>
    #include "Exception.hpp"
    #include "Factory.hpp"


namespace Abstract {
    class Core;
    typedef void (Core::*function)(std::string);
    class Core {
        public:
            Core();
            ~Core();
            void run();
            void checkArguments(int ac, char **av);
            void setStream(std::istream *stream);
            void compute();
            void computeEntry(std::istream& in);
            void parseFile(std::istream& in);
            void parseLine(std::string line);

            void assert(std::string value);
            void load(std::string value);
            void push(std::string value);

            void add(std::string value);
            void clear(std::string value);
            void div(std::string value);
            void dump(std::string value);
            void dup(std::string value);
            void exit(std::string value);
            void mod(std::string value);
            void mul(std::string value);
            void pop(std::string value);
            void print(std::string value);
            void store(std::string value);
            void sub(std::string value);
            void swap(std::string value);
            std::map <std::string, function> _mapFunctions;

            std::map<std::string, eOperandType> _typeMap = {
                {"int8", eOperandType::Int8},
                {"int16", eOperandType::Int16},
                {"int32", eOperandType::Int32},
                {"float", eOperandType::Float},
                {"double", eOperandType::Double},
                {"bigdecimal", eOperandType::BigDecimal}
            };
        private:
            bool _isRunning;
            std::string _fileName;
            std::vector<std::pair <std::string, std::string>> _commands;
            std::list<IOperand *> _stack;
            std::list<IOperand *> _registers;
            //std::map<int, IOperand *> _registers;
    };
}

#endif /* !CORE_HPP_ */
