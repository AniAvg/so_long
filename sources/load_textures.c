/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:37:19 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/21 13:37:21 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player_textures(t_game *game)
{
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/vimpire.xpm",
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
	game->current = game->player;
}

void	load_collectible_textures(t_game *game)
{
	game->collect.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/collectible.xpm",
			&game->collect.width, &game->collect.height);
	if (!game->collect.img)
		print_error("Error: Failed to load collectible texture!\n");
	// game->collect2.img = mlx_xpm_file_to_image(game->mlx,
	// 		"./textures/coll2.xpm",
	// 		&game->collect2.width, &game->collect2.height);
	// if (!game->collect2.img)
	// 	print_error("Error: Failed to load collectible texture!\n");
	// game->collect3.img = mlx_xpm_file_to_image(game->mlx,
	// 		"./textures/coll3.xpm",
	// 		&game->collect3.width, &game->collect3.height);
	// if (!game->collect3.img)
	// 	print_error("Error: Failed to load collectible texture!\n");
	// game->collect4.img = mlx_xpm_file_to_image(game->mlx,
	// 		"./textures/coll4.xpm",
	// 		&game->collect4.width, &game->collect4.height);
	// if (!game->collect4.img)
	// 	print_error("Error: Failed to load collectible texture!\n");
}

void	load_environment_textures(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&game->wall.width, &game->wall.height);
	if (!game->wall.img)
		print_error("Error: Failed to load wall texture!\n");
	game->empty_space.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/empty_space.xpm",
			&game->empty_space.width, &game->empty_space.height);
	if (!game->empty_space.img)
		print_error("Error: Failed to load empty space texture!\n");
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
			&game->exit.width, &game->exit.height);
	if (!game->exit.img)
		print_error("Error: Failed to load exit texture!\n");
}

void	load_enemy_textures(t_game *game)
{
	game->enemy.img = mlx_xpm_file_to_image(game->mlx, "./textures/enemy.xpm",
			&game->enemy.width, &game->enemy.height);
	if (!game->enemy.img)
		print_error("Error: Failed to load enemy texture!\n");
	// game->enemy2.img = mlx_xpm_file_to_image(game->mlx, "./textures/enemy2.xpm",
	// 		&game->enemy2.width, &game->enemy2.height);
	// if (!game->enemy2.img)
	// 	print_error("Error: Failed to load enemy2 texture!\n");
	// game->enemy3.img = mlx_xpm_file_to_image(game->mlx, "./textures/enemy3.xpm",
	// 		&game->enemy3.width, &game->enemy3.height);
	// if (!game->enemy3.img)
	// 	print_error("Error: Failed to load enemy3 texture!\n");
	// game->enemy4.img = mlx_xpm_file_to_image(game->mlx, "./textures/enemy4.xpm",
	// 		&game->enemy4.width, &game->enemy4.height);
	// if (!game->enemy4.img)
	// 	print_error("Error: Failed to load enemy4 texture!\n");
}

void	load_textures(t_game *game)
{
	load_player_textures(game);
	load_collectible_textures(game);
	load_environment_textures(game);
	load_enemy_textures(game);
}
