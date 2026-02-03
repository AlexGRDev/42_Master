# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/25 18:10:40 by agarcia2          #+#    #+#              #
#    Updated: 2026/02/02 20:18:46 by agarcia2         ###   ########.fr        #
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
	src/algo/sort_big.c \
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

DEBUG_SRCS = src/debug/debug.c
DEBUG_OBJS = $(DEBUG_SRCS:.c=.o)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# ============================
#   COMPILACIÓN CON DEBUG
# ============================

debug: CFLAGS += -DDEBUG
debug: $(OBJS) $(DEBUG_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(DEBUG_OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS) $(DEBUG_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug