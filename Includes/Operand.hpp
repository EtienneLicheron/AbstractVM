/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** Operand
*/

#ifndef OPERAND_HPP_
    #define OPERAND_HPP_
    #include "IOperand.hpp"
    #include "Factory.hpp"
    #include <cmath>

namespace Abstract {
    template <typename T>
    class Operand : public IOperand {
        public:
            Operand(const T &value, eOperandType type) : _value(value), _type(type){}
            std::string toString() const {return std::to_string(_value);};
            eOperandType getType() const {return _type;};

            IOperand* operator+(const IOperand &rhs) const
            {
                return Factory::createOperand(this->getType(), std::to_string(std::stold(rhs.toString()) + std::stold(this->toString())));
            }
            IOperand* operator-(const IOperand &rhs) const
            {
                return Factory::createOperand(this->getType(), std::to_string(std::stold(this->toString()) - std::stold(rhs.toString())));
            }
            IOperand* operator*(const IOperand &rhs) const
            {
                return Factory::createOperand(this->getType(), std::to_string(std::stold(rhs.toString()) * std::stold(this->toString())));
            }
            IOperand* operator/(const IOperand &rhs) const
            {
                if (_type > rhs.getType())
                    return Factory::createOperand(_type, std::to_string(std::stold(rhs.toString()) / std::stold(this->toString())));
                else
                    return Factory::createOperand(rhs.getType(), std::to_string(std::stold(rhs.toString()) / std::stold(this->toString())));
            }
            IOperand* operator%(const IOperand &rhs) const
            {
                if (_type > rhs.getType())
                    return Factory::createOperand(_type, std::to_string(std::fmod(std::stold(this->toString()), std::stold(rhs.toString()))));
                else
                    return Factory::createOperand(rhs.getType(), std::to_string(std::fmod(std::stold(this->toString()), std::stold(rhs.toString()))));
            }
        private:
            T _value;
            eOperandType _type;
    };
}

#endif /* !OPERAND_HPP_ */
