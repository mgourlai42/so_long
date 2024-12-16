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

void	mapchecking(t_game *game)
{
	game->info_map.mapisok = 1;
	checkshape(game);
	checkborder(game);
	checkcontent(game);
	checkoccurences(game);
	checkpath(game);
}

void	startgame(char **argv)
{
	t_game		game;
	int			fd1;
	int			fd2;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[1], O_RDONLY);
	initmap(&game);
	makemap (fd1, fd2, &game);
	close(fd1);
	close(fd2);
	fd2 = open(argv[1], O_RDONLY);
	makebuffer(fd2, &game);
	close(fd2);
	mapchecking(&game);
	graphic_hub(&game);
}

int	checkberfile(char **argv)
{
	int	i;

	i = ft_strlen(argv[1]) - 1;
	if (argv[1][i] == 'r')
	{
		i--;
		if (argv[1][i] == 'e')
		{
			i--;
			if (argv[1][i] == 'b')
			{
				i--;
				if (argv[1][i] == '.')
					i--;
			}
		}
	}
	else
		return (0);
	return (1);
}

int	argerrors(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("error\nYou forgot to add an argument!", 2);
		return (0);
	}
	if (argc > 2)
	{
		ft_putstr_fd("error\nPick only one .ber file as argument!", 2);
		return (0);
	}
	if (checkberfile(argv) == 0)
	{
		ft_putstr_fd("error\nYour map needs to be a .ber file!", 2);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argerrors(argc, argv) == 0)
		return (0);
	startgame(argv);
	return (0);
}
