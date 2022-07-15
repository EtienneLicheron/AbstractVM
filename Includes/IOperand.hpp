/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** IOperand
*/

#ifndef IOPERAND_HPP_
    #define IOPERAND_HPP_
    #include <string>
    #include <map>
    #include <limits>
    #include <iomanip>
    #include "Exception.hpp"

namespace Abstract {
    typedef enum eOperandType_s {
        Int8,
        Int16,
        Int32,
        Float,
        Double,
        BigDecimal
    }eOperandType;

    class IOperand {
        public:
            virtual std::string toString() const = 0;
            virtual eOperandType getType() const = 0;
            virtual IOperand* operator+(const IOperand &rhs) const = 0;
            virtual IOperand* operator-(const IOperand &rhs) const = 0;
            virtual IOperand* operator*(const IOperand &rhs) const = 0;
            virtual IOperand* operator/(const IOperand &rhs) const = 0;
            virtual IOperand* operator%(const IOperand &rhs) const = 0;
            virtual ~IOperand() {};
    };
}

#endif /* !IOPERAND_HPP_ */
