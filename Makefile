##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for plazza
##

NAME            = plazza

SRC             =	src/basic_function.cpp \
			src/Cmd.cpp \
			src/Core.cpp \
			src/ConditionalVar.cpp \
			src/Mutex.cpp \
			src/Parser.cpp \
			src/Task.cpp \
			src/ThreadPool.cpp \
			src/Pipe.cpp \
			src/Dispatch.cpp \
			src/main.cpp

CC              = g++

RM              = rm -rf

OBJ             = $(SRC:.cpp=.o)

CXXFLAGS        += -I./include -I.

CXXFLAGS        += -W -Wall -Wextra -std=c++11

all:
	@make --no-print-directory $(NAME)

$(NAME):        $(OBJ)
	$(CC)   $(OBJ) -lpthread -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
