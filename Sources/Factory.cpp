/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** Factory
*/

#include "Factory.hpp"

namespace Abstract
{
    Factory::Factory()
    {
        
    }

    IOperand* Factory::createOperand(eOperandType type, std::string &value)
    {
        //return new Operand<char>(std::stoi(value));
    }

    IOperand *Factory::createInt8(const std::string &value)
    {
        return new Operand<char>(std::stoi(value));
    }
    IOperand *Factory::createInt16(const std::string &value)
    {
        return new Operand<short>(std::stoi(value));
    }
    IOperand *Factory::createInt32(const std::string &value)
    {
        return new Operand<int>(std::stoi(value));
    }
    IOperand *Factory::createFloat(const std::string &value)
    {
        return new Operand<float>(std::stoi(value));
    }
    IOperand *Factory::createDouble(const std::string &value)
    {
        return new Operand<double>(std::stoi(value));
    }
    IOperand *Factory::createBigDecimal(const std::string &value)
    {
        return new Operand<long double>(std::stoi(value));
    }
}