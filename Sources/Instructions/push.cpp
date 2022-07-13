/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** push
*/

#include "Core.hpp"

namespace Abstract {
    void Core::push(std::string value) {
        std::map<std::string, eOperandType> _typeMap = {
            {"int8", eOperandType::Int8},
            {"int16", eOperandType::Int16},
            {"int32", eOperandType::Int32},
            {"float", eOperandType::Float},
            {"double", eOperandType::Double},
            {"bigdecimal", eOperandType::BigDecimal}
        };
        std::string valueTmp = value.substr(value.find_first_of('(') + 1);
        eOperandType type = _typeMap[valueTmp];
        std::cout << type << std::endl;
        _stack.push_back(Factory::createOperand(type, value));
    }
}