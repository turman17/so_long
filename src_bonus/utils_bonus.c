/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:15:04 by vtryason          #+#    #+#             */
/*   Updated: 2023/07/01 15:28:45 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_images(t_map *game)
{
	mlx_destroy_image(game->initmlx, game->img.ptr);
	mlx_destroy_image(game->initmlx, game->wall.ptr);
	mlx_destroy_image(game->initmlx, game->player.ptr);
	mlx_destroy_image(game->initmlx, game->exit.ptr);
	mlx_destroy_image(game->initmlx, game->collect.ptr);
	mlx_destroy_image(game->initmlx, game->floor.ptr);
	mlx_destroy_image(game->initmlx, game->killer.ptr);
}

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

void	exit_game(t_map *game)
{
	free_map(game->map);
	free_images(game);
	if (game->winmlx)
		mlx_destroy_window(game->initmlx, game->winmlx);
	mlx_destroy_display(game->initmlx);
	free(game->initmlx);
	exit(0);
}

int	format_check(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
	{
		ft_printf("Not .ber address");
		exit(1);
	}
	else if (str[len - 4] == '.' && str[len - 3] == 'b' && str[len - 2] == 'e'
		&& str[len - 1] == 'r')
		return (0);
	else
	{
		ft_printf("Not .ber address");
		exit(1);
	}
}
