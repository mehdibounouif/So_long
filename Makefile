NAME = so_long
RM = rm -f
CC = cc
MLX_FLAGS = -L/usr/include/minilibx-linux -lmlx -lXext -lX11
FLAGS = -Wall -Wextra -Werror -g3
SRC_DIR = ./source
SRC = $(SRC_DIR)/handel_list.c\
      $(SRC_DIR)/helper_func.c\
      $(SRC_DIR)/check_map.c\
      $(SRC_DIR)/check_name.c\
      $(SRC_DIR)/check_walls.c\
      $(SRC_DIR)/ft_free.c\
      $(SRC_DIR)/check_rectangle.c\
      $(SRC_DIR)/check_player.c\
      $(SRC_DIR)/check_collectible.c\
      $(SRC_DIR)/check_invalid_char.c\
      $(SRC_DIR)/if_can_access.c\
      $(SRC_DIR)/mlx_func.c\
      $(SRC_DIR)/so_long.c\

LIBFT_DIR = ./libft

LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRC_OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
all: $(NAME)

$(NAME): $(SRC_OBJ) $(LIBFT_LIB)
	$(CC) $(FLAGS) $(SRC_OBJ) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) --no-print-directory -C $(LIBFT_DIR)

clean:
	$(MAKE) --no-print-directory clean -C $(LIBFT_DIR)
	$(RM) $(SRC_DIR)/*.o

fclean: clean
	$(MAKE) --no-print-directory fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re
