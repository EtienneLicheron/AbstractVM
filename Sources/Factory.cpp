/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** Factory
*/

#include "Factory.hpp"
#include "Operand.hpp"
#include <iostream>

namespace Abstract
{
    IOperand* Factory::createOperand(eOperandType type, const std::string &value)
    {
        const std::function<IOperand*(const std::string value)> functions[6] = {
            createInt8,
            createInt16,
            createInt32,
            createFloat,
            createDouble,
            createBigDecimal
        };
        return functions[type](value);
    }

    IOperand* Factory::createInt8(const std::string &value)
    {
        if (std::stoi(value) > std::numeric_limits<int8_t>::max() || std::stoi(value) < std::numeric_limits<int8_t>::min())
            throw Exception("Type value overflow");
        return new Operand<int8_t>(std::stoi(value), Int8);
    }

    IOperand* Factory::createInt16(const std::string &value)
    {
        if (std::stold(value) > std::numeric_limits<int16_t>::max() || std::stold(value) < std::numeric_limits<int16_t>::min())
            throw Exception("Type value overflow");
        return new Operand<int16_t>(std::stoi(value), Int16);
    }

    IOperand* Factory::createInt32(const std::string &value)
    {
        if (std::stold(value) > std::numeric_limits<int32_t>::max() || std::stold(value) < std::numeric_limits<int32_t>::min())
            throw Exception("Type value overflow");
        return new Operand<int32_t>(std::stoi(value), Int32);
    }

    IOperand* Factory::createFloat(const std::string &value)
    {
        if (std::stof(value) > std::numeric_limits<float>::max() || std::stof(value) < std::numeric_limits<float>::min())
            throw Exception("Type value overflow");
        return new Operand<float>(std::stold(value), Float);
    }

    IOperand* Factory::createDouble(const std::string &value)
    {
        if (std::stod(value) > std::numeric_limits<double>::max() || std::stod(value) < std::numeric_limits<double>::min())
            throw Exception("Type value overflow");
        return new Operand<double>(std::stold(value), Double);
    }

    IOperand* Factory::createBigDecimal(const std::string &value)
    {
        if (std::stod(value) > std::numeric_limits<long double>::max() || std::stod(value) < std::numeric_limits<long double>::min())
            throw Exception("Type value overflow");
        return new Operand<long double>(std::stold(value), BigDecimal);
    }
}