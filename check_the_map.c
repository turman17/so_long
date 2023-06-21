/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:12:19 by vtryason          #+#    #+#             */
/*   Updated: 2023/06/21 17:45:35 by vtryason         ###   ########.fr       */
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

int	check_line_length(int result, int tmp_res)
{
	if (result != tmp_res)
	{
		ft_printf("Inconsistent line length\n");
		return (-1);
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

int	check_the_map(t_map *window, char *map)
{
	int		fd;
	char	*tmp;
	int		result;
	int		tmp_res;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening file");
		return (-1);
	}
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		window->height++;
		if (window->height == 1)
		{
			result = ft_strlen(tmp);
			window->width = result - 1;
		}
		count_characters(tmp, window);
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp != NULL)
		{
			tmp_res = ft_strlen(tmp);
			check_line_length(result, tmp_res);
		}
	}
	if (tmp != NULL)
		free(tmp);
	check_counts(window);
	return (0);
}
