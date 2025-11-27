# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 10:01:29 by agarcia2          #+#    #+#              #
#    Updated: 2025/11/27 09:51:28 by agarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
CC		=	cc
CFLAGS		= 	-Wall -Werror -Wextra
ASAN_FLAGS	=	-g3 -fsanitize=address
RM		= 	rm -f
 
SRCS		= 	main.c	pipex.c pipex_utils.c
OBJS		= 	$(SRCS:.c=.o)
LIBFTPRINTF	=	ft_printf/libftprintf.a
LIBFTPRINTF_DIR	=	ft_printf
LIBFT		=	ft_printf/LibFT/libft.a
LIBFT_DIR	=	ft_printf/LibFT
 
all: $(NAME)
 
$(NAME): $(OBJS) $(LIBFTPRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) $(LIBFT) -o $(NAME)
 
$(LIBFTPRINTF):
	$(MAKE) -C $(LIBFTPRINTF_DIR)
 
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
 
%.o: %.c  Makefile pipex.h
	$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFTPRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
 
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTPRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean
 
re: fclean all

asan: fclean
	$(MAKE) CFLAGS="$(CFLAGS) $(ASAN_FLAGS)" all

.PHONY: all clean fclean re asan
