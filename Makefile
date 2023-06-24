NAME = so_long


SRCS = so_long.c check_the_map.c put_textures.c hook.c utils.c
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address -Iinc/
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