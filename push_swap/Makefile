# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/25 18:10:40 by agarcia2          #+#    #+#              #
#    Updated: 2026/01/26 10:41:58 by agarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -fsanitize=address,undefined -g3
INCLUDE     = -I include -I /usr/local/include
LIBFT       = -L /usr/local/lib -lft

SRCS = \
	src/main.c \
	src/algo/controller.c \
	src/algo/small/short_2.c \
	src/algo/small/short_3.c \
	src/algo/small/short_mid.c \
	src/algo/small/sort_big.c \
	src/algo/chunks/chunk_utils.c \
	src/algo/chunks/chunk_costs.c \
	src/algo/chunks/chunk_move.c \
	src/parse/parse.c \
	src/parse/parse_args.c \
	src/parse/parse_clean.c \
	src/parse/parse_validate.c \
	src/utils/index.c \
	src/utils/parse_utils.c \
	src/utils/others.c \
	src/movements/push/pa.c \
	src/movements/push/pb.c \
	src/movements/swap/sa.c \
	src/movements/swap/sb.c \
	src/movements/swap/ss.c \
	src/movements/rotate/ra.c \
	src/movements/rotate/rb.c \
	src/movements/rotate/rr.c \
	src/movements/reverse_rotate/rra.c \
	src/movements/reverse_rotate/rrb.c \
	src/movements/reverse_rotate/rrr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re