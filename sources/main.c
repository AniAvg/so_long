/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavgya@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:26:36 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/27 15:52:15 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->map = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->height = 0;
	game->width = 0;
	game->collect_count = 0;
	game->steps = 0;
}

void	init_images(t_game *game)
{
	int	i;

	i = 0;
	game->player.img = NULL;
	game->player_left.img = NULL;
	game->player_right.img = NULL;
	game->wall.img = NULL;
	game->empty_space.img = NULL;
	game->exit.img = NULL;
	game->current.img = NULL;
	while (i < 4)
	{
		game->anim.collect[i].img = NULL;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		game->anim.enemy[i].img = NULL;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc == 1 || argc > 2)
		print_error("Error\nWrong Arguments.\nUsage: ./so_long map.ber\n");
	if (!valid_path(argv[1]))
		print_error("Error\nInvalid path.\n");
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	init_game(game);
	init_images(game);
	game->map = load_map(game, argv[1]);
	if (!game->map)
	{
		free_game(game);
		print_error("Error\nFailed to load map.\n");
	}
	make_window(game);
	free_game(game);
	return (0);
}
