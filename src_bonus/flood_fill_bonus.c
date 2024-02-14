/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:07:41 by vtryason          #+#    #+#             */
/*   Updated: 2023/07/01 18:04:36 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	cleaner(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	flood_fill(char **map, int x, int y, int *counter)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'E' || map[y][x] == 'C')
		*counter += 1;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, counter);
	flood_fill(map, x - 1, y, counter);
	flood_fill(map, x, y + 1, counter);
	flood_fill(map, x, y - 1, counter);
}

int	build_the_map(t_map *game)
{
	int		i;
	char	**tmp_map;
	int		counter;

	i = -1;
	tmp_map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (tmp_map == NULL)
		return (0);
	counter = 0;
	while (game->map[++i])
		tmp_map[i] = ft_strdup(game->map[i]);
	tmp_map[i] = NULL;
	flood_fill(tmp_map, game->p_x, game->p_y, &counter);
	cleaner(tmp_map);
	if (counter == (game->e_count + game->c_count))
		return (0);
	else
	{
		ft_printf("Exit or collectible is not reachible");
		exit(1);
	}
}
