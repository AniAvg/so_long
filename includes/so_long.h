/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:29:47 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/02 17:51:50 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <../mlx/mlx.h>

# define SIZE 128

typedef struct  s_texture
{
	void	*img;
	int		height;
	int		width;
}	t_texture;

typedef struct	s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	t_texture	player;
	t_texture	wall;
	t_texture	empty_space;
	t_texture	collect;
	t_texture	exit;
	int		height;
	int		width;
	int		collect_count;
}	t_game;

// utils.c
void	print_error(char *str);
void	free_split(char **str);

// arg_validation.c
int		valid_path(char *path);

// checking_walls.c
int		check_left_right_walls(char **map_lines, int row_count);
int		check_up_down_walls(char **map_lines, int column_count);
int		checking_walls(char **map_lines, int row_count, int column_count);

// map_parsing.c
int		column_count_check(char **map_lines, int row_count, int column_count);
int		row_count_check(char **map_lines, int row_count, int column_count);
int		characters_count_check(char **map_lines, int row_count, char c);
int		valid_characters(char **map_lines, int row_count, int column_count);
int		valid_map(char **map_lines, int row_count, int column_count);

// open_map.c
char	*get_map_lines(int fd);
char	**open_map(char *path);

// main.c
void	make_window(t_game *game);
void	load_textures(t_game *game);
void	create_map(t_game *game);
void	put_image(t_game *game, char c, int i, int j);
#endif