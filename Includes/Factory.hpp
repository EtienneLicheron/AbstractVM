/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
    #define FACTORY_HPP_
    #include "Operand.hpp"

namespace Abstract {
    class Factory;
    //typedef IOperand* (Factory::*fn)(std::string const &value);
    class Factory {
        public:
            Factory();
            static IOperand* createOperand(eOperandType type, std::string &value);
        private:
            IOperand* createInt8(const std::string& value);
            IOperand* createInt16(const std::string& value);
            IOperand* createInt32(const std::string& value);
            IOperand* createFloat(const std::string& value);
            IOperand* createDouble(const std::string& value);
            IOperand* createBigDecimal(const std::string& value);
    };
}

#endif /* !FACTORY_HPP_ */
