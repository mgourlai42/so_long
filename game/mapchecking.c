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

int	checkcontent2(t_game *game, int i, int j)
{
	if (game->info_map.map[i][j] == '1' || \
		game->info_map.map[i][j] == '0' || \
		game->info_map.map[i][j] == 'C' || \
		game->info_map.map[i][j] == 'E' || \
		game->info_map.map[i][j] == 'P' || \
		game->info_map.map[i][j] == 'N')
	{
		if (game->info_map.map[i][j] == 'N')
			game->info_map.enemycount += 1;
		j++;
	}
	else
	{
		game->info_map.mapisok = 0;
		return (1);
	}
	return (0);
}

// checking that the map only has '1', '0', 'C', 'E' 'N' or 'P'
void	checkcontent(t_game *game)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	while (game->info_map.map[i][j] && i <= game->info_map.linecount - 2)
	{
		while (game->info_map.map[i][j++] && j < \
			(int)ft_strlen(game->info_map.map[i] + 1))
		{
			ret = checkcontent2(game, i, j);
			if (ret == 1)
			{
				game->info_map.mapisok = 0;
				return ;
			}
		}
		j = 0;
		i++;
	}
}

// checking that the map is a rectangle
void	checkshape(t_game *game)
{
	int	i;

	i = 1;
	while (game->info_map.map[i])
	{
		if (ft_strlen(game->info_map.map[i]) != \
			ft_strlen(game->info_map.map[i - 1]))
			game->info_map.mapisok = 0;
		i++;
	}
	return ;
}

void	checkborder_top_bot(t_game *game)
{
	int		i;
	int		bottom;

	i = 0;
	bottom = game->info_map.linecount - 1;
	while (i < game->info_map.x)
	{
		if (game->info_map.map[0][i] != '1')
			game->info_map.mapisok = 0;
		i++;
	}
	i = 0;
	while (i < game->info_map.x)
	{
		if (game->info_map.map[bottom][i] != '1')
			game->info_map.mapisok = 0;
		i++;
	}
}

// checking that the map is closed (walls on all sides)
void	checkborder(t_game *game)
{
	int		j;
	int		i;
	int		bottom;

	checkborder_top_bot(game);
	j = 0;
	i = 0;
	bottom = game->info_map.linecount ;
	while (j < bottom)
	{
		if (game->info_map.map[j][0] != '1')
			game->info_map.mapisok = 0;
		j++;
	}
	j = 0;
	while (j < bottom)
	{
		if (game->info_map.map[j][i] != '1')
		{
			game->info_map.mapisok = 0;
		}
		j++;
	}
}
