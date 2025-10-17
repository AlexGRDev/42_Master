# **************************************************************************** #
#                                   LIBFT                                      #
# **************************************************************************** #

NAME        = libft.a

# Directorios
OBJDIR      = objs

# Comandos
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -rf
MKDIR       = mkdir -p

# Archivos
SRC         = $(wildcard *.c)
OBJ         = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

# **************************************************************************** #

all: $(NAME)

# Regla principal: librería depende de objetos
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Regla de compilación de .c a .o en objs/
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Crear directorio objs si no existe
$(OBJDIR):
	$(MKDIR) $(OBJDIR)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
