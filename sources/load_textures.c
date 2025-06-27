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
		free_with_error(game, "Error\nFailed to load player texture!\n");
	game->player_left.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/vimpire_left.xpm", &game->player_left.width,
			&game->player_left.height);
	if (!game->player_left.img)
		free_with_error(game, "Error\nFailed to load player texture!\n");
	game->player_right.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/vimpire_right.xpm", &game->player_right.width,
			&game->player_right.height);
	if (!game->player_right.img)
		free_with_error(game, "Error\nFailed to load player texture!\n");
	game->current = game->player;
}

void	load_collectible_textures(t_game *game)
{
	game->anim.index_c = 0;
	game->anim.speed_c = 0;
	game->anim.index_e = 0;
	game->anim.speed_e = 0;
	game->anim.collect[0].img = mlx_xpm_file_to_image(game->mlx,
			"./textures/collectible.xpm",
			&game->anim.collect[0].width, &game->anim.collect[0].height);
	if (!game->anim.collect[0].img)
		free_with_error(game, "Error\nFailed to load collectible texture!\n");
	game->anim.collect[1].img = mlx_xpm_file_to_image(game->mlx,
			"./textures/coll2.xpm",
			&game->anim.collect[1].width, &game->anim.collect[1].height);
	if (!game->anim.collect[1].img)
		free_with_error(game, "Error\nFailed to load collectible texture!\n");
	game->anim.collect[2].img = mlx_xpm_file_to_image(game->mlx,
			"./textures/coll3.xpm",
			&game->anim.collect[2].width, &game->anim.collect[2].height);
	if (!game->anim.collect[2].img)
		free_with_error(game, "Error\nFailed to load collectible texture!\n");
	game->anim.collect[3].img = mlx_xpm_file_to_image(game->mlx,
			"./textures/coll4.xpm",
			&game->anim.collect[3].width, &game->anim.collect[3].height);
	if (!game->anim.collect[3].img)
		free_with_error(game, "Error\nFailed to load collectible texture!\n");
}

void	load_environment_textures(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&game->wall.width, &game->wall.height);
	if (!game->wall.img)
		free_with_error(game, "Error\nFailed to load wall texture!\n");
	game->empty_space.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/empty_space.xpm",
			&game->empty_space.width, &game->empty_space.height);
	if (!game->empty_space.img)
		free_with_error(game, "Error\nFailed to load empty space texture!\n");
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
			&game->exit.width, &game->exit.height);
	if (!game->exit.img)
		free_with_error(game, "Error\nFailed to load exit texture!\n");
}

void	load_enemy_textures(t_game *game)
{
	game->anim.enemy[0].img = mlx_xpm_file_to_image(game->mlx,
			"./textures/enemy.xpm",
			&game->anim.enemy[0].width, &game->anim.enemy[0].height);
	if (!game->anim.enemy[0].img)
		free_with_error(game, "Error\nFailed to load enemy texture!\n");
	game->anim.enemy[1].img = mlx_xpm_file_to_image(game->mlx,
			"./textures/enemy2.xpm",
			&game->anim.enemy[1].width, &game->anim.enemy[1].height);
	if (!game->anim.enemy[1].img)
		free_with_error(game, "Error\nFailed to load enemy texture!\n");
	game->anim.enemy[2].img = mlx_xpm_file_to_image(game->mlx,
			"./textures/enemy3.xpm",
			&game->anim.enemy[2].width, &game->anim.enemy[2].height);
	if (!game->anim.enemy[2].img)
		free_with_error(game, "Error\nFailed to load enemy texture!\n");
	game->anim.enemy[3].img = mlx_xpm_file_to_image(game->mlx,
			"./textures/enemy4.xpm",
			&game->anim.enemy[3].width, &game->anim.enemy[3].height);
	if (!game->anim.enemy[3].img)
		free_with_error(game, "Error\nFailed to load enemy texture!\n");
}

void	load_textures(t_game *game)
{
	load_player_textures(game);
	load_collectible_textures(game);
	load_environment_textures(game);
	load_enemy_textures(game);
}
