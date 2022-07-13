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
            Operand(T value);
            std::string toString() const;
            eOperandType getType() const;
            IOperand* operator+(const IOperand &rhs) const;
            IOperand* operator-(const IOperand &rhs) const;
            IOperand* operator*(const IOperand &rhs) const;
            IOperand* operator/(const IOperand &rhs) const;
            IOperand* operator%(const IOperand &rhs) const;
            ~Operand();
        private:
    };
}

#endif /* !OPERAND_HPP_ */
