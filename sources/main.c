/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:33:17 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/10 12:42:46 by anavagya         ###   ########.fr       */
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
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&game->wall.width, &game->wall.height);
	if (!game->wall.img)
		print_error("Error: Failed to load the texture!\n");
	game->player.img = mlx_xpm_file_to_image(game->mlx, "./textures/vimpire.xpm",
			&game->player.width, &game->player.height);
	if (!game->player.img)
		print_error("Error: Failed to load the texture!\n");
	game->empty_space.img = mlx_xpm_file_to_image(game->mlx, "./textures/empty_space.xpm",
			&game->empty_space.width, &game->empty_space.height);
	if (!game->empty_space.img)
		print_error("Error: Failed to load the texture!\n");
	game->collect.img = mlx_xpm_file_to_image(game->mlx, "./textures/collectible.xpm",
			&game->collect.width, &game->collect.height);
	if (!game->collect.img)
		print_error("Error: Failed to load the texture!\n");
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
			&game->exit.width, &game->exit.height);
	if (!game->exit.img)
		print_error("Error: Failed to load the texture!\n");
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
	void	*mlx;

	if (argc > 2)
		print_error("Error: Wrong Arguments.\nUsage: ./so_long path\n");
	if (!valid_path(argv[1]))
		print_error("Error: Invalid path\n.");
	open_map(argv[1]);
	
	return (0);
}
