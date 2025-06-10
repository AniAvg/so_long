/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:33:17 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/09 16:25:51 by anavagya         ###   ########.fr       */
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

void	load_textures(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, "../textures/wall.xpm", SIZE, SIZE);
	if (!game->wall)
		print_error("Error: Failed to load the texture!");
	game->empty_space = mlx_xpm_file_to_image(game->mlx, "../textures/empty_space.xpm", SIZE, SIZE);
	if (!game->empty_space)
		print_error("Error: Failed to load the texture!");
	game->player = mlx_xpm_file_to_image(game->mlx, "../textures/vimpire.xpm", SIZE, SIZE);
	if (!game->player)
		print_error("Error: Failed to load the texture!");
	game->collect = mlx_xpm_file_to_image(game->mlx, "../textures/collectible.xpm", SIZE, SIZE);
	if (!game->collect)
		print_error("Error: Failed to load the texture!");
	game->exit = mlx_xpm_file_to_image(game->mlx, "../textures/exit.xpm", SIZE, SIZE);
	if (!game->exit)
		print_error("Error: Failed to load the texture!");
}

int	main(int argc, char **argv)
{
	void	*mlx;

	if (argc > 2)
		print_error("Error: Wrong Arguments.\nUsage: ./so_long path\n");
	if (!valid_path(argv[1]))
		print_error("Error: Invalid path\n.");
	open_map(argv[1]);
	
	return (0);
}
