/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:42:26 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/10 14:25:38 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int i, int j)
{
	if (game->map[game->player_x + i][game->player_y + j] == '1')
		return ;
	if (game->map[game->player_x + i][game->player_y + j] == 'C')
	{
		game->collect_count--;
		game->map[game->player_x + i][game->player_y + j] == '0';
	}
	if (game->map[game->player_x + i][game->player_y + j] == 'E')
	{
		if (game->collect_count <= 0)
		{
			game->steps++;
			
		}
		else
			return ;	
	}
}

int	handle_keys(t_game *game, int keycode)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, 1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, -1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
}