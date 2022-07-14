/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** Operand
*/

#ifndef OPERAND_HPP_
    #define OPERAND_HPP_
    #include "IOperand.hpp"

namespace Abstract {
    template <typename T>
    class Operand : public IOperand {
        public:
            Operand(const T &value, eOperandType type) : _value(value), _type(type){}
            std::string toString() const {return std::to_string(_value);};
            eOperandType getType() const {return _type;};
            IOperand* operator+(const IOperand &rhs) const { return NULL; };
            IOperand* operator-(const IOperand &rhs) const { return NULL; };
            IOperand* operator*(const IOperand &rhs) const { return NULL; };
            IOperand* operator/(const IOperand &rhs) const { return NULL; };
            IOperand* operator%(const IOperand &rhs) const { return NULL; };
        private:
            T _value;
            eOperandType _type;
    };
}

#endif /* !OPERAND_HPP_ */
