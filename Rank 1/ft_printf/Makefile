# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexgarcia2 <agarcia2@student.42barcelo    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/11 21:26:50 by alexgarcia2       #+#    #+#              #
#    Updated: 2026/01/12 08:43:55 by alexgarcia2      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libftprintf.a
SRC	:= ft_printf.c ft_printf_utils.c ft_printf_utils2.c
OBJ	:= $(SRC:.c=.o)

CC	:= cc
CFLAGS	:= -Wall -Werror -Wextra

ASAN	:= -fsanitize=address,undefined

AR	:= ar
ARFLAGS	:= rcs

all: $(NAME)

$(NAME): $(OBJ) Makefile ft_printf.h
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

asan: CFLAGS += $(ASAN)
asan: re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re asan