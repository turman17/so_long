NAME = so_long
BONUS = so_long_bonus

SRCS =	src/so_long.c src/check_the_map.c src/put_textures.c \
		src/hook.c src/utils.c src/flood_fill.c \
		src/errors.c
OBJS = $(SRCS:.c=.o)

B_SRCS =	src_bonus/so_long_bonus.c src_bonus/check_the_map_bonus.c \
			src_bonus/put_textures_bonus.c src_bonus/hook_bonus.c \
			src_bonus/utils_bonus.c src_bonus/flood_fill_bonus.c \
			src_bonus/errors_bonus.c src_bonus/utils_bonus_2.c
B_OBJS = $(B_SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -g  #-fsanitize=address -Iinc/
MLXFLAGS = -lXext -lX11 -lm -lz
LIBFT = Libft/libft.a
MLX = mlx_linux/libmlx_Linux.a

all: $(NAME) $(BONUS)

.PHONY: all, clean, fclean, re, bonus

$(NAME): $(OBJS)
		make -C Libft/
		cc $(FLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME) 

$(BONUS): $(B_OBJS)
		cc $(FLAGS) $(B_OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(BONUS)

clean:
	rm -f $(OBJS) $(B_OBJS)
	make fclean -C Libft/
	
fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all
