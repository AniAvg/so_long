#include "so_long.h"

void	load_player_textures(t_game *game)
{
	game->current.img = mlx_xpm_file_to_image(game->mlx, "./textures/vimpire.xpm",
		&game->current.width, &game->current.height);
	if (!game->current.img)
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

void	load_environment_textures(t_game *game)
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
