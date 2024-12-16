/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:19:22 by mgourlai          #+#    #+#             */
/*   Updated: 2023/06/06 17:19:24 by mgourlai         ###   ########.fr       */
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

void	move_up(t_game *game)
{
	if (game->info_map.map[game->player.y - 1][game->player.x] == 'E' && \
		game->info_map.collected != game->info_map.collectibles)
		return ;
	else if (game->info_map.map[game->player.y - 1][game->player.x] == 'E' && \
		game->info_map.collected == game->info_map.collectibles)
	{
		closegame(game);
		exit (0);
	}
	mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr, \
		game->sprites.dirt, game->player.x * 32, game->player.y * 32);
	game->player.y = game->player.y - 1;
	if (game->player.y == game->enemy.y && game->player.x == game->enemy.x)
	{
		ft_putstr_fd("Donttouchthechimkin!!", 1);
		closegame(game);
	}
	game->info_map.steps += 1;
	mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr, \
		game->sprites.character, game->player.x * 32, game->player.y * 32);
	if (game->info_map.map[game->player.y][game->player.x] == 'C')
	{
		game->info_map.collected++;
		game->info_map.map[game->player.y][game->player.x] = '0';
	}
}

void	move_down(t_game *game)
{
	if (game->info_map.map[game->player.y + 1][game->player.x] == 'E' && \
		game->info_map.collected != game->info_map.collectibles)
		return ;
	else if (game->info_map.map[game->player.y + 1][game->player.x] == 'E' && \
		game->info_map.collected == game->info_map.collectibles)
	{
		closegame(game);
		exit (0);
	}
	mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr, \
		game->sprites.dirt, game->player.x * 32, game->player.y * 32);
	game->player.y = game->player.y + 1;
	if (game->player.y == game->enemy.y && game->player.x == game->enemy.x)
	{
		ft_putstr_fd("Donttouchthechimkin!!", 1);
		closegame(game);
	}
	game->info_map.steps += 1;
	mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr, \
		game->sprites.character, game->player.x * 32, game->player.y * 32);
	if (game->info_map.map[game->player.y][game->player.x] == 'C')
	{
		game->info_map.collected++;
		game->info_map.map[game->player.y][game->player.x] = '0';
	}
}

void	move_left(t_game *game)
{
	if (game->info_map.map[game->player.y][game->player.x - 1] == 'E' && \
		game->info_map.collected != game->info_map.collectibles)
		return ;
	else if (game->info_map.map[game->player.y][game->player.x - 1] == 'E' && \
		game->info_map.collected == game->info_map.collectibles)
	{
		closegame(game);
		exit (0);
	}
	mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr, \
		game->sprites.dirt, game->player.x * 32, game->player.y * 32);
	game->player.x = game->player.x - 1;
	if (game->player.y == game->enemy.y && game->player.x == game->enemy.x)
	{
		ft_putstr_fd("Donttouchthechimkin!!", 1);
		closegame(game);
	}
	game->info_map.steps += 1 ;
	mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr, \
		game->sprites.character, game->player.x * 32, game->player.y * 32);
	if (game->info_map.map[game->player.y][game->player.x] == 'C')
	{
		game->info_map.collected++;
		game->info_map.map[game->player.y][game->player.x] = '0';
	}
}

void	move_right(t_game *game)
{
	if (game->info_map.map[game->player.y][game->player.x + 1] == 'E' && \
		game->info_map.collected != game->info_map.collectibles)
		return ;
	else if (game->info_map.map[game->player.y][game->player.x + 1] == 'E' && \
		game->info_map.collected == game->info_map.collectibles)
	{
		closegame(game);
		exit (0);
	}
	mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr, \
		game->sprites.dirt, game->player.x * 32, game->player.y * 32);
	game->player.x = game->player.x + 1;
	if (game->player.y == game->enemy.y && game->player.x == game->enemy.x)
	{
		ft_putstr_fd("Donttouchthechimkin!!", 1);
		closegame(game);
	}
	game->info_map.steps += 1;
	mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr, \
		game->sprites.character, game->player.x * 32, game->player.y * 32);
	if (game->info_map.map[game->player.y][game->player.x] == 'C')
	{
		game->info_map.collected++;
		game->info_map.map[game->player.y][game->player.x] = '0';
	}
}
