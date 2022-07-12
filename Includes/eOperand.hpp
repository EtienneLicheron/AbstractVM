// /*
// ** EPITECH PROJECT, 2022
// ** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
// ** File description:
// ** eOperand
// */

// #ifndef EOPERAND_HPP_
//     #define EOPERAND_HPP_
//     #include "IOperand.hpp"

// namespace Abstract {
//     class eOperand : public IOperand {
//         private:
//             std::string _value;
//             eOperandType _type;
//         public:
//             eOperand(const std::string value, eOperandType type) {_value = value; _type = type;};
//             virtual std::string toString() const {return _value;};
//             virtual eOperandType getType() const {return this->_type;};
//             virtual IOperand* operator+(const IOperand &rhs) const {return NULL;};
//             virtual IOperand* operator-(const IOperand &rhs) const {return NULL;};
//             virtual IOperand* operator*(const IOperand &rhs) const {return NULL;};
//             virtual IOperand* operator/(const IOperand &rhs) const {return NULL;};
//             virtual IOperand* operator%(const IOperand &rhs) const {return NULL;};
//             ~eOperand() {};
//     };
// }

// #endif /* !EOPERAND_HPP_ */
