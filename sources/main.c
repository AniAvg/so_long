/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavgya@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:26:36 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/25 18:38:11 by anavagya         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc == 1 || argc > 2)
		print_error("Error: Wrong Arguments.\nUsage: ./so_long map.ber\n");
	if (!valid_path(argv[1]))
		print_error("Error: Invalid path.\n");
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	init_game(game);
	game->map = load_map(game, argv[1]);
	if (!game->map)
	{
		free_game(game);
		print_error("Error: Failed to load map.\n");
	}
	make_window(game);
	free_game(game);
	return (0);
}
