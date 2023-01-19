NAME = a.out
CC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

SRCS = ./main.cpp ./Bureaucrat.cpp ./AForm.cpp ./ShrubberyCreationForm.cpp
OBJS = $(SRCS:.cpp=.o)
OFS = *_shrubbery

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) ${OFS}

fclean: clean
	$(RM) $(NAME) ${OFS}

re:
	make fclean
	make all

.PHONY: all clean fclean re