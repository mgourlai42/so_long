/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 03:00:55 by mgourlai          #+#    #+#             */
/*   Updated: 2023/06/04 03:00:57 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
//#include "minilibx-linux/mlx.h"
#include "get_next_line_bonus.h"
#include "countlines.h"
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "so_long.h"

void	filltiles(t_game *game, int x, int y)
{
	if (x < 1 || y < 1 || y > game->info_map.linecount || \
		x >= game->info_map.x || game->info_map.buffer[y][x] == '1')
	{
		return ;
	}
	game->info_map.buffer[y][x] = '1';
	filltiles(game, x - 1, y);
	filltiles(game, x + 1, y);
	filltiles(game, x, y -1);
	filltiles(game, x, y +1);
}

void	finalcheck(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->info_map.buffer[i][j] && i <= game->info_map.linecount - 2)
	{
		while (game->info_map.buffer[i][j] && j < \
			(int)ft_strlen(game->info_map.buffer[i] + 1))
		{
			if (game->info_map.buffer[i][j] != '1' || \
				game->info_map.buffer[i][j] != '0')
			{
				game->info_map.mapisok = 0;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	printf("map is %d\n", game->info_map.mapisok);
	printf("map checked entirely\n");
}

//counts amount of collectibles present on the map
void	count_collectibles(t_game *game)
{
	int	x;
	int	y;

	game->info_map.collectibles = 0;
	x = 0;
	y = 0;
	while (y < game->info_map.linecount)
	{
		while (game->info_map.map[y][x] != '\0')
		{
			if (game->info_map.map[y][x] == 'C')
			{
				game->info_map.collectibles++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	find_enemy(t_game *game)
{
	game->enemy.x = 0;
	game->enemy.y = 0;
	while (game->info_map.buffer[game->enemy.y][game->enemy.x])
	{
		while (game->info_map.buffer[game->enemy.y][game->enemy.x] != '\0')
		{
			if (game->info_map.buffer[game->enemy.y][game->enemy.x] == 'N')
			{
				return ;
			}
			game->enemy.x++;
		}
		game->enemy.x = 0;
		game->enemy.y++;
	}
}

// changes player coordinates in structure to current position
void	find_player(t_game *game)
{
	game->player.x = 0;
	game->player.y = 0;
	while (game->info_map.buffer[game->player.y][game->player.x])
	{
		while (game->info_map.buffer[game->player.y][game->player.x] != '\0')
		{
			if (game->info_map.buffer[game->player.y][game->player.x] == 'P')
			{
				return ;
			}
			game->player.x++;
		}
		game->player.x = 0;
		game->player.y++;
	}
}
