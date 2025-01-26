RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC = main.c arguments.c args_validate.c stack_utils.c push.c swap.c rotate.c reverse_rotate.c sort.c  sort_utils.c

OBJ = $(SRC:.c=.o)

$(LIBFT):
	make libft/

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) libft/libft.a

.PHONY: all clean fclean re

all: 
	cd Libft $$ make $@
	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
