// LIB = ar -rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC = main.c push_swap.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all