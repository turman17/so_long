/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:39:09 by vtryason          #+#    #+#             */
/*   Updated: 2023/06/27 13:44:42 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_wall(void)
{
	printf("Map is not surrounded by walls");
	exit(1);
}

void	check_counts(t_map *map)
{
	if (map->width == map->height)
	{
		ft_printf("Square is not allowed!!!\n");
		exit(1);
	}
	if (map->p_count != 1 || map->c_count < 1 || map->e_count != 1)
	{
		ft_printf("Invalid number of players, collectables, or exits.\n");
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
			printf("Wrong size");
			exit(1);
		}
	}
	return (0);
}
