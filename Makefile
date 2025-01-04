RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC = main.c push_swap.c

$(LIB):
	$(LIB)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) libft.a

.PHONY: all clean fclean re

all: 
	cd Libft $$ make $@
	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
