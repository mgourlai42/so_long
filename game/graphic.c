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

void	key_filter(int key, t_game *game)
{
	if (key == 65307)
	{
		closegame(game);
		exit (0);
	}
	if (key == 'w' && \
		game->info_map.map[game->player.y - 1][game->player.x] != '1' )
	{
		move_up(game);
	}
	if (key == 's' && \
		game->info_map.map[game->player.y + 1][game->player.x] != '1')
	{
		move_down(game);
	}
	if (key == 'a' && \
		game->info_map.map[game->player.y][game->player.x - 1] != '1')
	{
		move_left(game);
	}
	if (key == 'd' && \
		game->info_map.map[game->player.y][game->player.x + 1] != '1')
	{
		move_right(game);
	}
}

int	events(int key, t_game *game)
{
	if (game->info_map.enemycount > 0)
	{
		enemybehaviour(game);
	}
	game->info_map.stepcounter = ft_itoa(game->info_map.steps);
	key_filter(key, game);
	backgroundput(game);
	mlx_string_put(game->grph_serv_ptr, game->win_ptr, \
		15, 15, 0, "Current score : ");
	mlx_string_put(game->grph_serv_ptr, game->win_ptr, \
		115, 15, 0, game->info_map.stepcounter);
	free(game->info_map.stepcounter);
	game->info_map.stepcounter = NULL;
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	closegame(t_game *game)
{
	if (game->info_map.stepcounter)
		free(game->info_map.stepcounter);
	free_tab(game->info_map.map);
	mlx_destroy_image(game->grph_serv_ptr, game->sprites.rock);
	mlx_destroy_image(game->grph_serv_ptr, game->sprites.grass);
	mlx_destroy_image(game->grph_serv_ptr, game->sprites.dirt);
	mlx_destroy_image(game->grph_serv_ptr, game->sprites.tomato);
	mlx_destroy_image(game->grph_serv_ptr, game->sprites.flower);
	mlx_destroy_image(game->grph_serv_ptr, game->sprites.character);
	mlx_destroy_image(game->grph_serv_ptr, game->sprites.chimkin);
	mlx_destroy_image(game->grph_serv_ptr, game->sprites.chimkinup);
	if (game->win_ptr)
		mlx_destroy_window(game->grph_serv_ptr, game->win_ptr);
	if (game->grph_serv_ptr)
	{
		mlx_destroy_display(game->grph_serv_ptr);
		free(game->grph_serv_ptr);
	}
	exit(0);
}

void	graphic_hub(t_game *game)
{
	game->grph_serv_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->grph_serv_ptr, game->info_map.x * 32, \
		game->info_map.y * 32, "donttouchthechimkin");
	initializesprites(game);
	parsing(game);
	mlx_hook(game->win_ptr, 2, 1, events, game);
	mlx_hook(game->win_ptr, 17, 0, closegame, game);
	mlx_loop(game->grph_serv_ptr);
}
