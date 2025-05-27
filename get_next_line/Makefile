# Nom de la bibliothèque
NAME = gln.a

# Compilateur et options
CC = clang
CFLAGS = -Wall -Wextra -Werror

# Fichiers source
SRC = get_next_line.c get_next_line_utils.c

# Fichiers objets
OBJ = $(SRC:.c=.o)

# Règles
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
