##
## EPITECH PROJECT, 2022
## undefined
## File description:
## Makefile
##


NAME	=	abstractVM

CXX	=	g++

RM	=	rm -f

SRCS	=	$(wildcard src/*.cpp)

OBJS	=	$(SRCS:.cpp=.o)

CXXFLAGS	=	-std=c++20 -g -Wall -Wextra -Werror -I include

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(OBJS) -g -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
