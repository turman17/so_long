/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:12:19 by vtryason          #+#    #+#             */
/*   Updated: 2023/06/24 20:34:24 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	walls(t_map *game)
{
	int	x;
	int	y;
	int	len;

	y = 0;
	while (game->map[y])
	{
		len = ft_strlen(game->map[y]);
		if (len < 2 || game->map[y][0] != '1' || game->map[y][len - 1] != '1')
		{
			printf("Map is not surrounded by walls");
			exit(1);
		}
		if (y == 0 || game->map[y + 1] == NULL)
		{
			x = 0;
			while (game->map[y][x])
			{
				if (game->map[y][x] != '1')
				{
					printf("Map is not surrounded by walls");
					exit(1);
				}
				x++;
			}
		}
		y++;
	}
	return (0);
}

void	count_characters(char *tmp, t_map *map)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == 'P')
		{
			map->p_x = i;
			map->p_y = map->height;
			map->p_count++;
		}
		else if (tmp[i] == 'C')
			map->c_count++;
		else if (tmp[i] == 'E')
		{
			map->e_x = i;
			map->e_y = map->height;
			map->e_count++;
		}
		i++;
	}
}

void	read_map(char *file, t_map *window)
{
	char	*tmp;
	char	*tmp_result;
	char	*result;
	int		fd;

	fd = open(file, O_RDONLY);
	result = ft_strdup("");
	while (fd)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp_result = ft_strjoin(result, tmp);
		free(result);
		result = tmp_result;
		count_characters(tmp, window);
		window->height++;
		free(tmp);
	}
	window->map = ft_split(result, '\n');
	free(result);
	if (window->map[0] == 0)
		exit(1);
	window->width = ft_strlen(window->map[0]);
	check_line_length(window);
	walls(window);
	check_counts(window);
	close(fd);
}
