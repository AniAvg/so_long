/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reachability.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavgya@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:17:13 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/23 18:16:26 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_game *game)
{
	int		i;
	char	**map_copy;

	i = 0;
	map_copy = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!map_copy)
		return (NULL);
	while (i < game->height)
	{
		map_copy[i] = (char *)malloc(sizeof(char) * (game->width + 1));
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
		}
		ft_strlcpy(map_copy[i], game->map[i], game->width + 1);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	flood_fill(char **map, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->height || y >= game->width)
		return ;
	if (map[x][y] == 'C' || map[x][y] == 'P')
		map[x][y] = '0';
	if (map[x][y] == '1' || map[x][y] == 'F')
		return ;
	if (map[x][y] == 'E')
	{
		map[x][y] = '1';
		return ;
	}
	if (map[x][y] != '0')
		return ;
	map[x][y] = 'F';
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x + 1, y);
	flood_fill(map, game, x, y - 1);
	flood_fill(map, game, x, y + 1);
}

int	check_reachability(t_game *game)
{
	int		i;
	int		j;
	char	**map_copy;

	i = 0;
	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	player_position(game);
	flood_fill(map_copy, game, game->player_y, game->player_x);
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (map_copy[i][j] != 'F' && map_copy[i][j] != '1'
				&& map_copy[i][j] != '0')
				return (free_map(map_copy), 0);
			j++;
		}
		i++;
	}
	free_map(map_copy);
	return (1);
}
