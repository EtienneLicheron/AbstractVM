/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_
    #include <iostream>
    #include <string>
    #include <vector>
    #include <unistd.h>
    #include <fstream>
    #include "Exception.hpp"

namespace Abstract {
    class Core {
        public:
            Core();
            ~Core();
            void run();
            void checkArguments(int ac, char **av);
            void setStream(std::istream *stream);
        private:
            bool _isRunning;
            std::istream *_stream;
    };
}

#endif /* !CORE_HPP_ */
