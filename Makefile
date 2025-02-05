# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 19:51:16 by akwadran          #+#    #+#              #
#    Updated: 2025/02/05 21:28:39 by akwadran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC = main.c arguments.c args_validate.c stack_utils.c push.c swap.c rotate.c reverse_rotate.c sort1.c sort2.c sort_utils.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all
