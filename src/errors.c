/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:39:09 by vtryason          #+#    #+#             */
/*   Updated: 2023/09/10 13:08:34 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_wall(t_map *map)
{
	ft_printf("Map is not surrounded by walls\n");
	free_map(map->map);
	exit(1);
}

void	check_counts(t_map *map)
{
	if (map->width == map->height)
	{
		ft_printf("Square is not allowed!!!\n");
		free_map(map->map);
		exit(1);
	}
	if (map->p_count != 1 || map->c_count < 1 || map->e_count != 1)
	{
		ft_printf("Invalid number of players, collectables, or exits.\n");
		free_map(map->map);
		exit(1);
	}
}

int	check_line_length(t_map *game)
{
	int	y;

	y = 0;
	while (game->map[y] && game->map[y + 1])
	{
		if (ft_strlen(game->map[y]) == ft_strlen(game->map[y + 1])
			|| game->map[y + 1] == 0)
			y++;
		else
		{
			ft_printf("Wrong size\n");
			free_map(game->map);
			exit(1);
		}
	}
	return (0);
}

int	check_map(t_map *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0'
				&& game->map[y][x] != 'C' && game->map[y][x] != 'P'
				&& game->map[y][x] != 'E' && game->map[y][x] != '\n')
			{
				ft_printf("Wrong characters in the map\n");
				free_map(game->map);
				exit(1);
			}
		}
	}
	return (0);
}
