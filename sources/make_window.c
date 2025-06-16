#include "so_long.h"

void	make_window(t_game *game)
{
	// game->mlx = NULL;
	// game->mlx_win = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
		print_error("Error: Failed to initialize MiniLibX.\n");
	game->mlx_win = mlx_new_window(game->mlx, game->width * SIZE,
			game->height * SIZE, "so_long"); 
	if (!game->mlx_win)
		print_error("Errror: Can't make the window.\n");
	load_textures(game);
	create_map(game);
	//map_render(game);
	//mlx_hook(game->mlx_win, 2, 1L<<0, handle_keys, game);
	mlx_key_hook(game->mlx_win, handle_keys, game);
    mlx_hook(game->mlx_win, 17, 0, close_game, game);
	
	mlx_loop(game->mlx);
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
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->current.img,
			j * SIZE, i * SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->collect.img,
			j * SIZE, i * SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit.img,
			j * SIZE, i * SIZE);
}
