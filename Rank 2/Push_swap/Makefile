# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/22 02:23:37 by agarcia2          #+#    #+#              #
#    Updated: 2026/01/22 02:35:01 by agarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC = main.c \
      parse.c \
      utils.c \
      swap.c \
      push.c \
      rotate.c \
      rev_rotate.c \
      indexing.c \
      positions.c \
      costs.c \
      chunks.c \
      push_to_b.c \
      sort_small.c\
      sort_stack.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re