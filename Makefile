##
## EPITECH PROJECT, 2022
## B-SYN-400-MPL-4-1-abstractVM-etienne.licheron [WSL: Ubuntu]
## File description:
## Makefile
##

BIN 		= abstractVM

SRC 		= $(wildcard Sources/*.cpp)
SRC			+= $(wildcard Sources/Instructions/*.cpp)
OBJS 		= $(SRC:.cpp=.o)

CPPFLAGS 	= -W -Wall -Wextra -I ./Includes -fno-gnu-unique -g3

all: core

core:	$(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(BIN)

clean:
	$(RM) $(OBJS) *.gcno *gcda

fclean: clean
	$(RM) $(BIN)

re: fclean all

.PHONY: all core clean fclean re