/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:42:26 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/18 14:25:59 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
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
	game->collect_count = count_coins(game);
	if (game->map[game->player_y + j][game->player_x + i] == '1')
		return ;
	else if (game->map[game->player_y + j][game->player_x + i] == 'C')
	{
		game->collect_count--;
		game->map[game->player_y + j][game->player_x + i] = '0';
	}
	else if (game->map[game->player_y + j][game->player_x + i] == 'E')
	{
		if (game->collect_count == 0)
		{
			game->steps++;
			ft_printf("You Win!\n");
			exit(0);
		}
		return ;
	}
	put_image(game, '0', game->player_y, game->player_x);
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y + j][game->player_x + i] = 'P';
	put_image(game, 'P', game->player_y + j, game->player_x + i);
	game->steps++;
}

int	handle_keys(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->current.img = game->player.img;
		move_player(game, 0, -1);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->current.img = game->player.img;
		move_player(game, 0, 1);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->current.img = game->player_left.img;
		move_player(game, -1, 0);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->current.img = game->player_right.img;
		move_player(game, 1, 0);
	}
	else if (keycode == KEY_ESC)
		close_game(game);
	ft_printf("Steps: %d\n", game->steps);
	return (0);
}
