# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/25 22:49:28 by agarcia2          #+#    #+#              #
#    Updated: 2026/07/20 14:57:02 by agarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Werror -Wextra
ASAN	= -fsanitize=address,undefined,leaks -g3 -O0
AR      = ar rcs
RM      = rm -f
SRCS    = ft_printf.c	ft_putchar.c	ft_putstr.c	ft_putnbr.c	ft_putptr.c	\
	  ./LibFT/ft_strlen.c
OBJS    = $(SRCS:.c=.o)

TESTS_BIN	= test_ft_printf
TESTS_SRCS	= main.c	tests/test_char_str.c	tests/test_num_ptr.c	\
		  tests/test_suite.c

all: $(NAME)
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
%.o: %.c  Makefile ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME) $(TESTS_BIN)
re: fclean all
asan: fclean
	$(MAKE) CFLAGS="$(CFLAGS) $(ASAN)" all
tests: $(NAME)
	$(CC) $(CFLAGS) $(TESTS_SRCS) $(NAME) -o $(TESTS_BIN)
	./$(TESTS_BIN)

.PHONY: all clean fclean re asan tests
