/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:50:23 by vtryason          #+#    #+#             */
/*   Updated: 2023/06/21 20:40:19 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img.addr + (y * game->img.line_length + x * (game->img.bpp
				/ 8));
	*(unsigned int *)dst = color;
}

t_data	create_img(char *path, t_game *game)
{
	t_data	img;

	img.ptr = mlx_xpm_file_to_image(game->initmlx, path, &img.x, &img.y);
	img.addr = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}

void	init_images(t_map *game)
{
	game->img.ptr = mlx_new_image(game->initmlx, game->width * 64,
			game->height * 64);
	game->img.addr = mlx_get_data_addr(game->img.ptr,
										&(game->img.bits_per_pixel),
										&(game->img.line_length),
										&(game->img.endian));
	game->floor =   create_img("", game);
	game->wall = create_img("txt/wall.xpm", game);
	game->collect = create_img("txt/Colect.xpm", game);
	game->exit = create_img("txt/exit1.xpm", game);
	game->exit2 = create_img("text/exit2.xpm", game);
}

void	put_grafics(t_data *game)
{
	int x;
	int y;

	y = 0;
	while(game->size[y])
	{
		
	}
}