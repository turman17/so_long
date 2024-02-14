/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:27:13 by vtryason          #+#    #+#             */
/*   Updated: 2023/07/01 15:15:49 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_w(t_map *game)
{
	int	x;
	int	y;

	x = game->p_x;
	y = game->p_y;
	if (game->map[y - 1][x] == '1' || game->map[y - 1][x] == 'E'
		&& game->c_count != 0)
		return ;
	if (game->map[y - 1][x] == 'E' && game->c_count == 0)
		exit_game(game);
	else if (game->map[y - 1][x] == 'K')
		exit_game(game);
	else if (game->map[y - 1][x] == 'C')
		game->c_count--;
	refresh_grafics_player(game, x, y, 'w');
	game->map[y][x] = '0';
	game->map[y - 1][x] = 'P';
	game->p_y--;
	game->moves_count++;
}

void	move_s(t_map *game)
{
	int	x;
	int	y;

	x = game->p_x;
	y = game->p_y;
	if (game->map[y + 1][x] == '1' || game->map[y - 1][x] == 'E'
		&& game->c_count != 0)
		return ;
	if (game->map[y + 1][x] == 'E' && game->c_count == 0)
		exit_game(game);
	else if (game->map[y + 1][x] == 'K')
		exit_game(game);
	else if (game->map[y + 1][x] == 'C')
		game->c_count--;
	refresh_grafics_player(game, x, y, 's');
	game->map[y][x] = '0';
	game->map[y + 1][x] = 'P';
	game->p_y++;
	game->moves_count++;
}

void	move_a(t_map *game)
{
	int	x;
	int	y;

	x = game->p_x;
	y = game->p_y;
	if (game->map[y][x - 1] == '1' || game->map[y][x - 1] == 'E'
		&& game->c_count != 0)
		return ;
	if (game->map[y][x - 1] == 'E' && game->c_count == 0)
		exit_game(game);
	else if (game->map[y][x - 1] == 'K')
		exit_game(game);
	else if (game->map[y][x - 1] == 'C')
		game->c_count--;
	refresh_grafics_player(game, x, y, 'a');
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'P';
	game->p_x--;
	game->moves_count++;
}

void	move_d(t_map *game)
{
	int	x;
	int	y;

	x = game->p_x;
	y = game->p_y;
	if (game->map[y][x + 1] == '1' || game->map[y][x + 1] == 'E'
		&& game->c_count != 0)
		return ;
	if (game->map[y][x + 1] == 'E' && game->c_count == 0)
		exit_game(game);
	else if (game->map[y][x + 1] == 'K')
		exit_game(game);
	else if (game->map[y][x + 1] == 'C')
		game->c_count--;
	refresh_grafics_player(game, x, y, 'd');
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'P';
	game->p_x++;
	game->moves_count++;
}

int	hook(int keycode, t_map *game)
{
	if (keycode == 65307)
		exit_game(game);
	if (keycode == 119)
		move_w(game);
	if (keycode == 115)
		move_s(game);
	if (keycode == 97)
		move_a(game);
	if (keycode == 100)
		move_d(game);
	move_count(game);
	return (0);
}
