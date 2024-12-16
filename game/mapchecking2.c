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

// checking that the map has a path from P to C then E
void	checkpath(t_game *game)
{
	count_collectibles(game);
	find_player(game);
	if (game->info_map.enemycount > 0)
		find_enemy(game);
	filltiles(game, game->player.x, game->player.y);
	finalcheck(game);
}

void	checkmapelements(t_game *game, int counter_c, int counter_p, \
	int counter_e)
{
	if (counter_c < 1 || counter_p != 1 || counter_e != 1)
		game->info_map.mapisok = 0;
}

// checking that the map has at least one C AND exactly one P and one E
void	checkoccurences(t_game *game)
{
	int	i;
	int	j;
	int	counter_e;
	int	counter_p;
	int	counter_c;

	i = 0;
	j = 0;
	counter_e = 0;
	counter_p = 0;
	counter_c = 0;
	while (game->info_map.map[i++][j] && i < game->info_map.linecount -1)
	{
		while (game->info_map.map[i][j++] != '\0')
		{
			if (game->info_map.map[i][j] == 'E')
				counter_e++;
			else if (game->info_map.map[i][j] == 'P')
				counter_p++;
			else if (game->info_map.map[i][j] == 'C')
				counter_c++;
		}
		j = 0;
	}
	checkmapelements(game, counter_c, counter_p, counter_e);
}
