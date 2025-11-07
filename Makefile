NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror



SRC_DIR		=	src
LIBFT_DIR	=	libft
MLX_DIR		=	minilibx-linux




SRC			=	$(SRC_DIR)/map_utils.c \
				$(SRC_DIR)/parse_map.c \
				$(SRC_DIR)/render.c \
				$(SRC_DIR)/render_mv.c \
				$(SRC_DIR)/render_mv2.c \
				$(SRC_DIR)/presets.c \
				$(SRC_DIR)/texture.c \
				$(SRC_DIR)/utils.c \
				$(SRC_DIR)/flood_fill.c \
				$(SRC_DIR)/flood_fill2.c \
				so_long.c

OBJ			=	$(SRC:.c=.o)



LIBFT		=	$(LIBFT_DIR)/libft.a
MLX_LIB		=	$(MLX_DIR)/libmlx.a
MLX_FLAGS	=	-L$(MLX_DIR) -lmlx -lX11 -lXext -lm




all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
