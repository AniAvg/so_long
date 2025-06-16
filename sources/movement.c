/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:42:26 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/16 19:10:42 by anavagya         ###   ########.fr       */
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
	if (game->player_x + i < 0 || game->player_x + i >= game->width || 
        game->player_y + j < 0 || game->player_y + j >= game->height)
    {
        return; // Don't move if out of bounds
    }

	if (game->map[game->player_y + j][game->player_x + i] == '1')
	{
		printf("tf\n");
		return ;
	}
	else if (game->map[game->player_y + j][game->player_x + i] == 'C')
	{
		game->collect_count--;
		game->map[game->player_y + j][game->player_x + i] = '0';
	}
	else if (game->map[game->player_y + j][game->player_x + i] == 'E')
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
	map_render(game);
	//put_image(game, 'P', game->player_x + i, game->player_y + j);
	game->steps++;
}

int	handle_keys(int keycode, t_game *game)
{
	ft_printf("%d\n", keycode);
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

