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

void	laytiles2(t_game *game, int image_x, int image_y)
{
	if (game->info_map.map[game->sprites.tile_y][game->sprites.tile_x] \
		== 'P')
	{
		mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
			game->sprites.character, image_x, image_y);
	}
	else if (game->info_map.map[game->sprites.tile_y][game->sprites.tile_x] \
		== 'N')
	{
		mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
			game->sprites.chimkin, image_x, image_y);
	}
	else
	{
		mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
			game->sprites.tomato, image_x, image_y);
	}
}

void	laytiles(t_game *game)
{
	int	image_x;
	int	image_y;

	image_x = game->sprites.tile_x * IMAGE_WIDTH;
	image_y = game->sprites.tile_y * IMAGE_HEIGHT;
	if (game->info_map.map[game->sprites.tile_y][game->sprites.tile_x] \
		== '1')
	{
		mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
			game->sprites.rock, image_x, image_y);
	}
	else if (game->info_map.map[game->sprites.tile_y][game->sprites.tile_x] \
		== '0')
	{
		mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
			game->sprites.dirt, image_x, image_y);
	}
	else if (game->info_map.map[game->sprites.tile_y][game->sprites.tile_x] \
		== 'E')
	{
		mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
			game->sprites.flower, image_x, image_y);
	}
	else
		laytiles2(game, image_x, image_y);
}

void	initializesprites(t_game *game)
{
	int	size;

	size = 32;
	game->sprites.rock = mlx_xpm_file_to_image(game->grph_serv_ptr, \
		"sprites/xpm/rock.xpm", &size, &size);
	game->sprites.grass = mlx_xpm_file_to_image(game->grph_serv_ptr, \
		"sprites/xpm/grass.xpm", &size, &size);
	game->sprites.dirt = mlx_xpm_file_to_image(game->grph_serv_ptr, \
		"sprites/xpm/dirt.xpm", &size, &size);
	game->sprites.tomato = mlx_xpm_file_to_image(game->grph_serv_ptr, \
		"sprites/xpm/tomato.xpm", &size, &size);
	game->sprites.flower = mlx_xpm_file_to_image(game->grph_serv_ptr, \
		"sprites/xpm/flowers.xpm", &size, &size);
	game->sprites.character = mlx_xpm_file_to_image(game->grph_serv_ptr, \
		"sprites/xpm/character.xpm", &size, &size);
	game->sprites.chimkin = mlx_xpm_file_to_image(game->grph_serv_ptr, \
		"sprites/xpm/chimkin.xpm", &size, &size);
	game->sprites.chimkinup = mlx_xpm_file_to_image(game->grph_serv_ptr, \
		"sprites/xpm/chimkinup.xpm", &size, &size);
}

void	parsing(t_game	*game)
{
	game->sprites.tile_x = 0;
	game->sprites.tile_y = 0;
	while (game->sprites.tile_y < game->info_map.linecount)
	{
		while (game->sprites.tile_x < game->info_map.x)
		{
			laytiles(game);
			game->sprites.tile_x++;
		}
		game->sprites.tile_x = 0;
		game->sprites.tile_y++;
	}
}

void	backgroundput(t_game *game)
{
	mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
		game->sprites.rock, 0, 0);
	mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
		game->sprites.rock, 32, 0);
	mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
		game->sprites.rock, 64, 0);
	mlx_put_image_to_window(game->grph_serv_ptr, game->win_ptr,
		game->sprites.rock, 96, 0);
}
