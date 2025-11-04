# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/25 22:49:28 by agarcia2          #+#    #+#              #
#    Updated: 2025/11/04 07:31:05 by agarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Werror -Wextra
AR      = ar rcs
RM      = rm -r

SRCS    = ft_printf.c	ft_putchar.c	ft_putstr.c	ft_ptrintptr.c\
	  ft_putnbr.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c  Makefile ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean all
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
