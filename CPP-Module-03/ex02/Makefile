NAME = a.out
CC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

SRCS = ./main.cpp ./ClapTrap.cpp ./ScavTrap.cpp ./FragTrap.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re