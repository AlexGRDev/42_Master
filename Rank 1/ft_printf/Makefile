# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/25 22:49:28 by agarcia2          #+#    #+#              #
#    Updated: 2025/11/16 11:08:13 by agarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Werror -Wextra
ASAN_FLAGS = -g3 -fsanitize=address
AR      = ar rcs
RM      = rm -f

SRCS    = ft_printf.c	ft_putchar.c	ft_putstr.c	ft_printptr.c\
	  ft_putnbr.c	ft_putu.c	ft_printhex.c	./LibFT/ft_putchar_fd.c \
	./LibFT/ft_strlen.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c  Makefile ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

asan: fclean
	$(MAKE) CFLAGS="$(CFLAGS) $(ASAN_FLAGS)" all

.PHONY: all clean fclean re asan
