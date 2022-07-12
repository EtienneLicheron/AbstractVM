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
    #include "Exception.hpp"
    #include <iostream>
    #include <sstream>
    #include <iterator>
    #include <algorithm>
    // #include "Factory.hpp"
    // #include "eOperand.hpp"
    // #include "IOperand.hpp"


namespace Abstract {
    //typedef IOperand *(*PtrFonct)();

    class Core {
        public:
            Core();
            ~Core();
            void run();
            void checkArguments(int ac, char **av);
            void setStream(std::istream *stream);
            void compute();
            void parseFile(std::istream& in);
            void parseLine(std::string line);
        private:
            std::vector <std::string> _instructions;
            std::vector<std::pair <std::string, std::string>> _commands;
            //PtrFonct pf;
            //std::map<std::string, IOperand*(*pf)(const IOperand*)> _commands;
            std::string _fileName;
    };

    typedef enum eOperandType_s {
        Int8,
        Int16,
        Int32,
        Float,
        Double,
        BigDecimal
    }eOperandType;
}

#endif /* !CORE_HPP_ */
