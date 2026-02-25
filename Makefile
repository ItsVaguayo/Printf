NAME = libftprintf.a

# Compilador
CC = cc

# Eliminación de archivos
RM = rm -f

# Flags de compilación
CFLAGS = -Wall -Werror -Wextra -I.

# Archivos fuente
SRC = ft_printf.c Utilities_printf.c

# Archivos objeto
OBJS = $(SRC:.c=.o)

# Regla por defecto: compilamos la biblioteca
all: $(NAME)

# Crear la biblioteca estática
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Regla para compilar archivos .c a .o
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar los archivos .o
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

# Limpiar y eliminar la biblioteca
fclean: clean
	$(RM) $(NAME)

# Volver a compilar todo desde cero
re: fclean all

# Definir los objetivos como no archivos
.PHONY: all clean fclean re
