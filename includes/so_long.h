/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavgya@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:38:44 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/25 18:45:36 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <../mlx/mlx.h>

# define SCREEN_WIDTH 3840
# define SCREEN_HEIGHT 2032
# define SIZE 128

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_ESC 65307

typedef struct s_texture
{
	void	*img;
	int		height;
	int		width;
}	t_texture;

typedef struct s_anim
{
	t_texture	collect[4];
	t_texture	enemy[4];
	int			index;
	int			speed;
	// int		index_c;
	// int		index_e;
	// int		speed_c;
	// int		speed_e;
}	t_anim;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	char		*line;
	int			fd;
	int			player_x;
	int			player_y;
	int			height;
	int			width;
	int			collect_count;
	int			steps;
	t_texture	player;
	t_texture	player_left;
	t_texture	player_right;
	t_texture	wall;
	t_texture	empty_space;
	// t_texture	collect;
	// t_texture	collect2;
	// t_texture	collect3;
	// t_texture	collect4;
	// t_texture	enemy;
	// t_texture	enemy2;
	// t_texture	enemy3;
	// t_texture	enemy4;
	t_texture	exit;
	t_texture	current;
	t_anim		anim;
}	t_game;

// utils.c
void	print_error(char *str);
int		count_coins(t_game *game);

// free.c
void	free_map(char **map);
void	free_enemy_images(t_game *game);
void	free_images(t_game *game);
void	free_game(t_game *game);
int		close_game(t_game *game);

// arg_validation.c
int		valid_path(char *path);

// checking_walls.c
int		check_left_right_walls(char **map_lines, int row_count,
			int column_count);
int		check_up_down_walls(char **map_lines, int row_count, int column_count);
int		checking_walls(char **map_lines, int row_count, int column_count);

// map_validation.c
int		column_count_check(char **map_lines, int row_count, int column_count);
int		row_count_check(char **map_lines, int row_count, int column_count);
int		characters_count_check(char **map_lines, int row_count,
			int column_count, char c);
int		valid_characters(char **map_lines, int row_count, int column_count);
int		valid_map(t_game *game, char **map_lines);

// check_reachability.c
char	**copy_map(t_game *game);
void	flood_fill(char **map, t_game *game, int x, int y);
int		check_reachability(t_game *game);

// validation.c
int		map_size(t_game *game);
char	*get_map_lines(int fd);
void	validate_map(t_game *game, int fd, char *line);
void	parse_map(t_game *game, int fd, char *line);
char	**load_map(t_game *game, char *path);

// load_textures.c
void	load_player_textures(t_game *game);
void	load_collectible_textures(t_game *game);
void	load_environment_textures(t_game *game);
void	load_enemy_textures(t_game *game);
void	load_textures(t_game *game);

// movement.c
void	player_position(t_game *game);
void	move_player(t_game *game, int i, int j);
int		handle_keys(int keycode, t_game *game);

// animation.c
void	collectible_animation(t_anim *anim);
void	enemy_animation(t_anim *anim);
int 	loop_hook(void *param);

// make_window.c
void	make_window(t_game *game);
void	create_map(t_game *game);
void	put_image(t_game *game, char c, int i, int j);

// main.c
void	init_game(t_game *game);

#endif
