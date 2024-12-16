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

int	linelen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	makebuffer(int fd2, t_game *game)
{
	int	i;

	i = 0;
	game->info_map.buffer = malloc((sizeof(char *) * \
		(game->info_map.linecount +1)));
	if (!game->info_map.buffer)
		return ;
	while (1)
	{
		game->info_map.buffer[i] = get_next_line(fd2);
		if (game->info_map.buffer[i] == NULL)
			break ;
		i++;
	}
}

void	makemap(int fd1, int fd2, t_game *game)
{
	int	i;

	i = 0;
	startcount(fd1, game);
	game->info_map.map = malloc((sizeof(char *) * \
		(game->info_map.linecount +1)));
	if (!game->info_map.map)
		return ;
	while (1)
	{
		game->info_map.map[i] = get_next_line(fd2);
		if (game->info_map.map[i] == NULL)
			break ;
		i++;
	}
	game->info_map.y = game->info_map.linecount;
	game->info_map.x = ft_strlen(game->info_map.map[0]) - 1;
}

void	initmap(t_game *game)
{
	game->info_map.linecount = 0;
	game->info_map.collected = 0;
	game->info_map.collectibles = 0;
	game->info_map.steps = 0;
	game->info_map.enemycount = 0;
}
