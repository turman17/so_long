/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:15:04 by vtryason          #+#    #+#             */
/*   Updated: 2023/06/24 20:31:12 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	refresh_grafics_player(t_map *game, int x, int y, char flag)
{
	load_graphics(game, &game->floor, x, y);
	if (flag == 'w')
	{
		load_graphics(game, &game->floor, x, y - 1);
		load_graphics(game, &game->player, x, y - 1);
	}
	if (flag == 's')
	{
		load_graphics(game, &game->floor, x, y + 1);
		load_graphics(game, &game->player, x, y + 1);
	}
	if (flag == 'a')
	{
		load_graphics(game, &game->floor, x - 1, y);
		load_graphics(game, &game->player, x - 1, y);
	}
	if (flag == 'd')
	{
		load_graphics(game, &game->floor, x + 1, y);
		load_graphics(game, &game->player, x + 1, y);
	}
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->img.ptr, 0, 0);
}
