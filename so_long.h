/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:41:59 by vtryason          #+#    #+#             */
/*   Updated: 2023/06/24 20:34:03 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}			t_data;

typedef struct s_map
{
	int		size;
	int		x;
	int		y;
	char	**map;
	int		p_count;
	int		c_count;
	int		e_count;
	int		width;
	int		height;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		moves_count;
	t_data	img;
	t_data	player;
	t_data	collect;
	t_data	floor;
	t_data	wall;
	t_data	exit2;
	t_data	exit;

	void	*initmlx;
	void	*winmlx;

}			t_map;

int			check_the_map(t_map *window, char *map);
void		init_images(t_map *game);
void		put_grafics(t_map *game);
void		read_map(char *file, t_map *window);
int			hook(int keycode, t_map *game);
void		load_graphics(t_map *game, t_data *type, int x_pos, int y_pos);
void		refresh_grafics_player(t_map *game, int x, int y, char flag);

#endif
