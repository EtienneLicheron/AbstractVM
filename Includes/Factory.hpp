/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
    #define FACTORY_HPP_
    #include "Operand.hpp"
    #include <functional>

namespace Abstract {
    class Factory {
        public:
            static IOperand* createOperand(eOperandType type, const std::string &value);
            typedef IOperand* (&function)(std::string &);
        private:
            static IOperand *createInt8(const std::string &value);
            static IOperand *createInt16(const std::string &value);
            static IOperand *createInt32(const std::string &value);
            static IOperand *createFloat(const std::string &value);
            static IOperand *createDouble(const std::string &value);
            static IOperand *createBigDecimal(const std::string &value);
    };

}

#endif /* !FACTORY_HPP_ */
