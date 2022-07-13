/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** Operand
*/

#include "Operand.hpp"

namespace Abstract {
    template <typename T>
    Operand<T>::Operand(T value) : _value(value)
    {
    } 
}
