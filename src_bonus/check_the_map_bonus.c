/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:12:19 by vtryason          #+#    #+#             */
/*   Updated: 2023/07/01 16:44:24 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	walls(t_map *game)
{
	int	x;
	int	y;
	int	len;

	y = -1;
	while (game->map[++y])
	{
		len = ft_strlen(game->map[y]);
		if (len < 2 || game->map[y][0] != '1' || game->map[y][len - 1] != '1')
			error_wall(game);
		if (y == 0 || game->map[y + 1] == NULL)
		{
			x = 0;
			while (game->map[y][x])
			{
				if (game->map[y][x] != '1')
					error_wall(game);
				x++;
			}
		}
	}
	return (0);
}

void	read_file(int fd, t_map *window, char **result)
{
	char	*tmp;
	char	*tmp_result;

	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp_result = ft_strjoin(*result, tmp);
		free(*result);
		*result = tmp_result;
		count_characters(tmp, window);
		window->height++;
		free(tmp);
	}
}

void	parse_map(char *result, t_map *window)
{
	window->map = ft_split(result, '\n');
	free(result);
	if (window->map[0] == 0)
		exit(1);
	window->width = ft_strlen(window->map[0]);
	check_line_length(window);
	walls(window);
	check_counts(window);
}

void	read_map(char *file, t_map *window)
{
	char	*result;
	int		fd;

	fd = open(file, O_RDONLY);
	result = ft_strdup("");
	read_file(fd, window, &result);
	parse_map(result, window);
	close(fd);
}
