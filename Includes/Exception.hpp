/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
    #define EXCEPTION_HPP_
    #include <string>
    #include <exception>

namespace Abstract {
    class Exception : public std::exception {
        public:
            Exception(std::string message);
            ~Exception();
            const char *what() const noexcept;
        private:
            const std::string _message;
    };
}

#endif /* !EXCEPTION_HPP_ */
