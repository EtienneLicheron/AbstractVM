/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** Exception
*/

#include "Exception.hpp"

namespace Abstract {
    Exception::Exception(std::string message) : _message(message)
    {
    }
    
    Exception::~Exception()
    {
    }
    
    const char *Exception::what() const noexcept
    {
        return _message.c_str();
    }
}