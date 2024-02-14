/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:44:44 by vtryason          #+#    #+#             */
/*   Updated: 2023/07/10 20:48:27 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	game;

	if (argc == 2)
	{
		format_check(argv[1]);
		ft_memset(&game, 0, sizeof(t_map));
		read_map(argv[1], &game);
		build_the_map(&game);
		game.initmlx = mlx_init();
		game.winmlx = mlx_new_window(game.initmlx, (game.width * 64),
				(game.height * 64), "Very yes");
		init_images(&game);
		mlx_key_hook(game.winmlx, &hook, &game);
		mlx_hook(game.winmlx, 17, 0L, (void *)exit_game, &game);
		mlx_loop(game.initmlx);
		free_map(game.map);
	}
	return (0);
}
