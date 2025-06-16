/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:43:27 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/13 16:25:39 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_destroy_image(game->mlx, game->current.img);
	mlx_destroy_image(game->mlx, game->player_left.img);
	mlx_destroy_image(game->mlx, game->player_right.img);
	mlx_destroy_image(game->mlx, game->wall.img);
	mlx_destroy_image(game->mlx, game->empty_space.img);
	mlx_destroy_image(game->mlx, game->collect.img);
	mlx_destroy_image(game->mlx, game->exit.img);
}

int	close_game(t_game *game)
{
	free_game(game);
	// if (game->mlx && game->mlx_win)
	// 	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

int count_coins(t_game *game)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
		    	count++;
			j++;
		}
		i++;
	}
	return (count);
}
