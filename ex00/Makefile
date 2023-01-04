NAME = zombie
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

SRCS = ./main.cpp ./newZombie.cpp ./randomChump.cpp ./Zombie.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re