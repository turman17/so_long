/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:50:23 by vtryason          #+#    #+#             */
/*   Updated: 2023/07/01 15:39:38 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pixel_put(t_map *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img.addr + (y * game->img.line_length + x
			* (game->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_data	create_img(char *path, t_map *game)
{
	t_data	img;

	if (!path || !*path || !game)
	{
		fprintf(stderr, "Invalid or empty image path or game structure.\n");
		exit(EXIT_FAILURE);
	}
	img.ptr = mlx_xpm_file_to_image(game->initmlx, path, &img.x, &img.y);
	if (!img.ptr)
	{
		fprintf(stderr, "Failed to load image: %s\n", path);
		exit(EXIT_FAILURE);
	}
	img.addr = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	if (!img.addr)
	{
		fprintf(stderr, "Failed to get data address from image: %s\n", path);
		exit(EXIT_FAILURE);
	}
	return (img);
}

void	init_images(t_map *game)
{
	game->img.ptr = mlx_new_image(game->initmlx, game->width * 64, game->height
			* 64);
	game->img.addr = mlx_get_data_addr(game->img.ptr,
			&(game->img.bits_per_pixel), &(game->img.line_length),
			&(game->img.endian));
	game->wall = create_img("textures/txt/wall.xpm", game);
	game->collect = create_img("textures/txt/Colect.xpm", game);
	game->exit = create_img("textures/txt/exit1.xpm", game);
	game->player = create_img("textures/characters/main.xpm", game);
	game->floor = create_img("textures/txt/floor.xpm", game);
	put_graphics(game);
}

void	load_graphics(t_map *game, t_data *type, int x_pos, int y_pos)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < type->y)
	{
		x = 0;
		while (x < type->x)
		{
			color = *(unsigned int *)(type->addr + y * type->line_length + x
					* (type->bits_per_pixel / 8));
			if (color != 4278190080)
				pixel_put(game, x_pos * 64 + x, y_pos * 64 + y, color);
			x++;
		}
		y++;
	}
}

void	put_graphics(t_map *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0' || game->map[y][x] == 'P'
				|| game->map[y][x] == 'C' || game->map[y][x] == '1'
				|| game->map[y][x] == 'E')
				load_graphics(game, &game->floor, x, y);
			if (game->map[y][x] == 'P')
				load_graphics(game, &game->player, x, y);
			if (game->map[y][x] == 'C')
				load_graphics(game, &game->collect, x, y);
			if (game->map[y][x] == '1')
				load_graphics(game, &game->wall, x, y);
			if (game->map[y][x] == 'E')
				load_graphics(game, &game->exit, x, y);
			x++;
		}
	}
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->img.ptr, 0, 0);
}
