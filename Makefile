NAME = so_long


SRCS = src/so_long.c src/check_the_map.c src/put_textures.c src/hook.c src/utils.c src/flood_fill.c src/errors.c
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -g # -fsanitize=address -Iinc/
MLXFLAGS = -lXext -lX11 -lm -lz
LIBFT = Libft/libft.a
MLX = mlx_linux/libmlx_Linux.a


all: $(NAME)

.PHONY: all, fclean, re

$(NAME): $(OBJS)
		make -C Libft/
		cc $(FLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME) 

clean:
	rm -f $(OBJS) $(B_OBJS)
	make fclean -C Libft/
	
fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all