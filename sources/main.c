/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:33:17 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/16 16:05:28 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_window(t_game *game)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
		print_error("Error: Failed to initialize MiniLibX.\n");
	game->mlx_win = mlx_new_window(game->mlx, game->width * SIZE,
			game->height * SIZE, "so_long"); 
	if (!game->mlx_win)
		print_error("Errror: Can't make the window.\n");
	load_textures(game);
	//create_map(game);
	map_render(game);
	mlx_hook(game->mlx_win, 2, 1L<<0, handle_keys, game);
	//mlx_key_hook(game->mlx_win, handle_keys, game);
    mlx_hook(game->mlx_win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}

static void	load_player_textures(t_game *game)
{
	game->player.img = mlx_xpm_file_to_image(game->mlx, "./textures/vimpire.xpm",
		&game->player.width, &game->player.height);
	if (!game->player.img)
		print_error("Error: Failed to load player texture!\n");
	game->player_left.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/vimpire_left.xpm", &game->player_left.width,
			&game->player_left.height);
	if (!game->player_left.img)
		print_error("Error: Failed to load player texture!\n");
	game->player_right.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/vimpire_right.xpm", &game->player_right.width,
			&game->player_right.height);
	if (!game->player_right.img)
		print_error("Error: Failed to load player texture!\n");
}

static void	load_environment_textures(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
		&game->wall.width, &game->wall.height);
	if (!game->wall.img)
		print_error("Error: Failed to load wall texture!\n");
	game->empty_space.img = mlx_xpm_file_to_image(game->mlx, "./textures/empty_space.xpm",
		&game->empty_space.width, &game->empty_space.height);
	if (!game->empty_space.img)
		print_error("Error: Failed to load empty space texture!\n");
	game->collect.img = mlx_xpm_file_to_image(game->mlx, "./textures/collectible.xpm",
		&game->collect.width, &game->collect.height);
	if (!game->collect.img)
		print_error("Error: Failed to load collectible texture!\n");
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
		&game->exit.width, &game->exit.height);
	if (!game->exit.img)
		print_error("Error: Failed to load exit texture!\n");
}

void	load_textures(t_game *game)
{
	load_player_textures(game);
	load_environment_textures(game);
}

void	create_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			put_image(game, game->map[i][j], i, j);
			j++;
		}
		i++;
	}
}

void	put_image(t_game *game, char c, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall.img,
			j * SIZE, i * SIZE);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->empty_space.img,
			j * SIZE, i * SIZE);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.img,
			j * SIZE, i * SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->collect.img,
			j * SIZE, i * SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit.img,
			j * SIZE, i * SIZE);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	game = malloc(sizeof(t_game));
	if(!game)
		return (1);
	if (argc == 1 || argc > 2)
		print_error("Error: Wrong Arguments.\nUsage: ./so_long map.ber\n");
	if (!valid_path(argv[1]))
		print_error("Error: Invalid path.\n");
	game->map = open_map(game, argv[1]);
	make_window(game);
	mlx_loop(game);
	return (0);
}
