// /*
// ** EPITECH PROJECT, 2022
// ** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
// ** File description:
// ** Factory
// */

// #include "Factory.hpp"

// namespace Abstract {
//     IOperand *Factory::createOperand(eOperandType type, const std::string &value)
//     {
//         switch (type) {
//             case Int8:
//                 return(createInt8(value));
//             case Int16:
//                 return(createInt16(value));
//             case Int32:
//                 return(createInt32(value));
//             case Float:
//                 return(createFloat(value));
//             case Double:
//                 return(createDouble(value));
//             case BigDecimal:
//                 return(createBigDecimal(value));
//             default:
//                 throw Exception("Unknown value type");
//         }
//     }
    
//     IOperand *Factory::createInt8(const std::string &value)
//     {
//         return new eOperand(value, Int8);
//     }
    
//     IOperand *Factory::createInt16(const std::string &value)
//     {
//         return new eOperand(value, Int16);
//     }
    
//     IOperand *Factory::createInt32(const std::string &value)
//     {
//         return new eOperand(value, Int32);
//     }
    
//     IOperand *Factory::createFloat(const std::string &value)
//     {
//         return new eOperand(value, Float);
//     }
    
//     IOperand *Factory::createDouble(const std::string &value)
//     {
//         return new eOperand(value, Double);
//     }
    
//     IOperand *Factory::createBigDecimal(const std::string &value)
//     {
//         return new eOperand(value, BigDecimal);
//     }
// }
