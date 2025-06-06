/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:33:17 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/05 16:24:08 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		print_error("Error: Failed to initialize MiniLibX.\n");
	game->mlx_win = mlx_new_window(game->mlx, game->height * SIZE,
			game->width * SIZE, "so_long");
	if (!game->mlx_win)
		print_error("Errror: Can't make the window.\n");
	mxl_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	void	*mlx;

	if (argc > 2)
		print_error("Error: Wrong Arguments.\nUsage: ./so_long path\n");
	if (!valid_path(argv[1]))
		print_error("Invalid path.");
	open_map(argv[1]);
	
	return (0);
}
