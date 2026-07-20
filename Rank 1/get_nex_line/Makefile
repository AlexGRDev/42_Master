# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.co> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 21:25:00 by agarcia2          #+#    #+#              #
#    Updated: 2026/07/17 14:15:59 by agarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= get_next_line.a
BONUS		= get_next_line_bns.a
INCLUDE		= include/get_next_line.h
INCLUDE_BNS	= include/get_next_line_bonus.h
SRCS		= src/get_next_line.c src/get_next_line_utils.c
SRC_BNS		= bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c
OBJS		= $(SRCS:.c=.o)
OBJS_BNS	= $(SRC_BNS:.c=.o)
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
ASAN		= -g3 -O0 -fsanitize=address,undefined,leak
AR		= ar rcs
RM		= rm -f

all: $(NAME)
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
bonus: $(BONUS)
$(BONUS): $(OBJS_BNS)
	$(AR) $(BONUS) $(OBJS_BNS)
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@
bonus/%.o: bonus/%.c $(INCLUDE_BNS)
	$(CC) $(CFLAGS) -c $< -o $@
asan: fclean
	$(MAKE) CFLAGS="$(CFLAGS) $(ASAN)" all
clean:
	$(RM) $(OBJS)
clean_bonus:
	$(RM) $(OBJS_BNS)
fclean: clean
	$(RM) $(NAME)
fclean_bonus: clean
	$(RM) $(BONUS)
re: fclean all

.PHONY: all bonus clean fclean re asan
