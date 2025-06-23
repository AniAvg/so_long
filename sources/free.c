/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavgya@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:28:11 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/23 18:16:19 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map || !*map)
		return ;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_images(t_game *game)
{
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->player_left.img)
		mlx_destroy_image(game->mlx, game->player_left.img);
	if (game->player_right.img)
		mlx_destroy_image(game->mlx, game->player_right.img);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->empty_space.img)
		mlx_destroy_image(game->mlx, game->empty_space.img);
	if (game->collect.img)
		mlx_destroy_image(game->mlx, game->collect.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->mlx && game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
}

void	free_game(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->map)
		free_map(game->map);
	free_images(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
}
