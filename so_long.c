/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:44:44 by vtryason          #+#    #+#             */
/*   Updated: 2023/06/24 16:32:45 by vtryason         ###   ########.fr       */
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

void free_map(char **map)
{
    int i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int	main(int argc, char **argv)
{
	t_map	game;

	ft_memset(&game, 0, sizeof(t_map));
	read_map(argv[1], &game);
	game.initmlx = mlx_init();
	game.winmlx = mlx_new_window(game.initmlx, (game.width * 64),
			(game.height * 64), "Very yes");
	init_images(&game);
	mlx_key_hook(game.winmlx, &hook, &game);
	// mlx_hook(game.winmlx, 17, 0L, (void *)exit_game, &game);
	mlx_loop(game.initmlx);
    free_map(game.map);

	return (0);
}
