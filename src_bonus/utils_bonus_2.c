/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:09:28 by vtryason          #+#    #+#             */
/*   Updated: 2023/07/05 16:53:25 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_count(t_map *win)
{
	char	*number;
	char	*out_put;

	number = ft_itoa(win->moves_count);
	out_put = ft_strjoin("Number of moves: ", number);
	mlx_string_put(win->initmlx, win->winmlx, 80, 300, 0xD60D00, out_put);
	free(number);
	free(out_put);
}

void	pixel_put(t_map *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img.addr + (y * game->img.line_length + x
			* (game->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	check_character(char character, int i, int height, t_map *map)
{
	if (character == 'P')
	{
		map->p_x = i;
		map->p_y = height;
		map->p_count++;
	}
	else if (character == 'C')
	{
		map->c_count++;
	}
	else if (character == 'E')
	{
		map->e_x = i;
		map->e_y = height;
		map->e_count++;
	}
	else if (character == 'K')
	{
		map->k++;
		map->k_x = i;
		map->k_y = height;
	}
}

void	count_characters(char *tmp, t_map *map)
{
	int	i;

	i = -1;
	while (tmp[++i])
	{
		check_map(tmp[i], map);
		check_character(tmp[i], i, map->height, map);
	}
}
