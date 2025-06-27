/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavgya@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:31:05 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/27 14:01:16 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_game *game)
{
	char	*moves;
	char	*str;

	moves = ft_itoa(game->steps);
	str = ft_strjoin("Moves: ", moves);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall.img, 0, 0);
	mlx_string_put(game->mlx, game->mlx_win, 20, 40, 0xFFFFFF, str);
	free(moves);
	free(str);
}

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

void	update_player_image(t_game *game, int i, int j)
{
	put_image(game, '0', game->player_y, game->player_x);
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y + j][game->player_x + i] = 'P';
	put_image(game, 'P', game->player_y + j, game->player_x + i);
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
	else if (game->map[game->player_y + j][game->player_x + i] == 'M')
		close_game(game);
	else if (game->map[game->player_y + j][game->player_x + i] == 'E')
	{
		if (game->collect_count == 0)
		{
			game->steps++;
			free_game(game);
			exit(0);
		}
		return ;
	}
	update_player_image(game, i, j);
	game->steps++;
	display_moves(game);
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
	return (0);
}
