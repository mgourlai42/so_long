/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:22:42 by mgourlai          #+#    #+#             */
/*   Updated: 2023/05/22 21:22:45 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "mlx.h"
#include "get_next_line_bonus.h"
#include "countlines.h"
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "so_long.h"

void	move_up_enemy(t_game *game)
{
	if (game->info_map.map[game->enemy.y - 1][game->enemy.x] == 'E')
		return ;
	mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
		game->sprites.dirt, game->enemy.x * 32, game->enemy.y * 32);
	game->enemy.y = game->enemy.y - 1;
	if (game->info_map.steps % 2 == 0)
		mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
			game->sprites.chimkin, game->enemy.x * 32, game->enemy.y * 32);
	else if (game->info_map.steps % 2 != 0)
		mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
			game->sprites.chimkinup, game->enemy.x * 32, game->enemy.y * 32);
}

void	move_down_enemy(t_game *game)
{
	if (game->info_map.map[game->enemy.y + 1][game->enemy.x] == 'E')
		return ;
	mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr, \
		game->sprites.dirt, game->enemy.x * 32, game->enemy.y * 32);
	game->enemy.y = game->enemy.y + 1;
	if (game->info_map.steps % 2 == 0)
		mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
			game->sprites.chimkin, game->enemy.x * 32, game->enemy.y * 32);
	else if (game->info_map.steps % 2 != 0)
		mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
			game->sprites.chimkinup, game->enemy.x * 32, game->enemy.y * 32);
}

void	move_left_enemy(t_game *game)
{
	if (game->info_map.map[game->enemy.y][game->enemy.x - 1] == 'E')
		return ;
	mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
		game->sprites.dirt, game->enemy.x * 32, game->enemy.y * 32);
	game->enemy.x = game->enemy.x - 1;
	if (game->info_map.steps % 2 == 0)
		mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
			game->sprites.chimkin, game->enemy.x * 32, game->enemy.y * 32);
	else if (game->info_map.steps % 2 != 0)
		mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
			game->sprites.chimkinup, game->enemy.x * 32, game->enemy.y * 32);
}

void	move_right_enemy(t_game *game)
{
	if (game->info_map.map[game->enemy.y][game->enemy.x + 1] == 'E')
		return ;
	mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
		game->sprites.dirt, game->enemy.x * 32, game->enemy.y * 32);
	game->enemy.x = game->enemy.x + 1;
	if (game->info_map.steps % 2 == 0)
		mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
			game->sprites.chimkin, game->enemy.x * 32, game->enemy.y * 32);
	else if (game->info_map.steps % 2 != 0)
		mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
			game->sprites.chimkinup, game->enemy.x * 32, game->enemy.y * 32);
}

void	enemybehaviour(t_game *game)
{
	if (rand() % 2 == 0 && \
		game->info_map.map[game->enemy.y][game->enemy.x - 1] != '1')
		move_left_enemy(game);
	if (rand() % 2 != 0 && \
		game->info_map.map[game->enemy.y][game->enemy.x + 1] != '1')
		move_right_enemy(game);
}
