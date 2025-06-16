/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:42:26 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/16 16:06:46 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_render(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	create_map(game);
}

void	player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->player_x = 0;
	game->player_y = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
				ft_printf("x = %d\ny = %d\n", game->player_x, game->player_y);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_player(t_game *game, int i, int j)
{
	player_position(game);
	if (game->map[game->player_y + j][game->player_x + i] == '1')
		return ;
	if (game->map[game->player_y + j][game->player_x + i] == 'C')
	{
		game->collect_count--;
		game->map[game->player_y + j][game->player_x + i] = '0';
	}
	if (game->map[game->player_y + j][game->player_x + i] == 'E')
	{
		if (game->collect_count == 0)
		{
			ft_printf("You Win!\n");
			game->steps++;
			exit(0);
		}
		//return ;	
	}
	ft_printf("Hiii\n");
	//put_image(game, '0', game->player_x, game->player_y);
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y + j][game->player_x + i] = 'P';
	//put_image(game, 'P', game->player_x + i, game->player_y + j);
	map_render(game);
	game->steps++;
}

int	handle_keys(t_game *game, int keycode)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->player = game->player_left;
		move_player(game, -1, 0);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->player = game->player_right;
		move_player(game, 1, 0);
	}
	else if (keycode == KEY_ESC)
		close_game(game);
	return (0);
}