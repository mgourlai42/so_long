/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:59:28 by mgourlai          #+#    #+#             */
/*   Updated: 2023/05/26 22:59:31 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include "mlx.h"
# define IMAGE_WIDTH 32
# define IMAGE_HEIGHT 32

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char	**map;
	char	**buffer;
	int	x;
	int	y;
	int	linecount;
	char	*nextline;
	int	mapisok;
	int	collectibles;
	int	enemycount;
	int	collected;
	int	steps;
	char	*stepcounter;
}	t_map;

typedef struct s_sprites
{
	void	*rock;
	void	*grass;
	void	*dirt;
	void	*tomato;
	void	*character;
	void	*flower;
	void	*chimkin;
	void	*chimkinup;
	int	tile_x;
	int	tile_y;
}	t_sprites;

typedef struct s_game
{
	void	*grph_serv_ptr;
	void	*win_ptr;
	t_sprites sprites;
	t_player player;
	t_player enemy;
	t_map info_map;
}	t_game;

// map checking functions
void	initgame(t_game game);
void	initmap(t_game *game);
void	mapchecking(t_game *game);
void	checkshape(t_game *game);
void	checkborder(t_game *game);
void	checkcontent(t_game *game);
void	makebuffer(int fd2, t_game *game);
void	makemap(int fd1, int fd2, t_game *game);
void	checkoccurences(t_game *game);
void	checkpath(t_game *game);
void	find_player(t_game *game);
void	find_enemy(t_game *game);
void	count_collectibles(t_game *game);
void	filltiles(t_game *game, int x, int y);
int	linelen(char *str);
int	checkcontent2(t_game *game, int i, int j);
void	finalcheck(t_game *game);

// graphic functions
void	graphic_hub(t_game *game);
void	initializesprites(t_game *game);
void	parsing(t_game *game);
void	laytiles(t_game *game);
// void	laytiles2(t_game *game, int image_x, int image_y);
void	backgroundput(t_game *game);

// character events functions
int	events(int key, t_game *game);
void	key_filter(int key, t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

// enemy animation
void	enemybehaviour(t_game *game);
void	move_right_enemy(t_game *game);
void	move_left_enemy(t_game *game);
void	move_down_enemy(t_game *game);
void	move_up_enemy(t_game *game);


// end functions
int	closegame(t_game *game);
#endif
