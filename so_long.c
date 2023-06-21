/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:44:44 by vtryason          #+#    #+#             */
/*   Updated: 2023/06/19 21:12:48 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	move(int keycode, t_vars *vars)
// {
// 	int	size;

// 	size = 10;
// 	if (keycode == 65307)
// 	{
// 		mlx_destroy_image(vars->mlx, vars->img.img);
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		mlx_destroy_display(vars->mlx);
// 		free(vars->mlx);
// 		exit(0);
// 	}
// 	if (keycode == 'w' && vars->y - size >= 0)
// 		vars->y -= size;
// 	else if (keycode == 'a' && vars->x - size >= 0)
// 		vars->x -= size;
// 	else if (keycode == 's' && vars->y + size < vars->img_height - size)
// 		vars->y += size;
// 	else if (keycode == 'd' && vars->x + size < vars->img_width - size)
// 		vars->x += size;
// 	else
// 		return (0);
// 	mlx_clear_window(vars->mlx, vars->win);
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, vars->x,
// 			vars->y);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;
// 	char	*relative_path;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "So_long");
// 	vars.x = 0;
// 	vars.y = 0;
// 	vars.img_width = 1920;
// 	vars.img_height = 1080;
// 	relative_path = "./textures/characters/main.xpm";
// 	int img_width, img_height;
// 	vars.img.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width,
// 			&img_height);
// 	if (vars.img.img == NULL)
// 	{
// 		ft_printf("Hello_world");
// 		ft_printf("Error loading image at path: %s\n", relative_path);
// 		mlx_destroy_window(vars.mlx, vars.win);
// 		free(vars.mlx);
// 		return (1);
// 	}
// 	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
// 			&vars.img.line_length, &vars.img.endian);
// 	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, vars.x, vars.y);
// 	mlx_hook(vars.win, 2, 1L << 0, move, &vars);
// 	mlx_loop(vars.mlx);
// }

int main(int ac, char **av)
{
	t_map map;
	
	ft_memset(&map, 0, sizeof(t_map));
	if(ac == 2)
	{
		check_the_map(&map, av[1]);
	}
}