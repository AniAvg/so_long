/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagy <anavgya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:28:09 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/21 17:18:55 by anavagy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	row_count_check(char **map_lines, int row_count, int column_count)
{
	int		i;
	int		j;
	int		len;
	char	*arr;

	j = 0;
	len = 0;
	while (j < column_count)
	{
		arr = (char *)malloc(row_count + 1);
		if (!arr)
			return (0);
		i = -1;
		while (map_lines[++i])
			arr[i] = map_lines[i][j];
		arr[i] = '\0';
		len = ft_strlen(arr);
		if (len != row_count)
			return (free(arr), 0);
		free(arr);
		j++;
	}
	return (1);
}

int	column_count_check(char **map_lines, int row_count, int column_count)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < row_count)
	{
		len = ft_strlen(map_lines[i]);
		if (len != column_count)
			return (0);
		i++;
	}
	return (1);
}

int	characters_count_check(char **map_lines, int row_count,
	int column_count, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < row_count)
	{
		j = 0;
		while (j < column_count)
		{
			if (map_lines[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if (c == 'C' && count < 1)
		return (0);
	else if ((c == 'P' && count != 1) || (c == 'E' && count != 1))
		return (0);
	return (1);
}

int	valid_characters(char **map_lines, int row_count, int column_count)
{
	int	i;
	int	j;

	i = 0;
	while (i < row_count)
	{
		j = 0;
		while (j < column_count)
		{
			if (map_lines[i][j] != '1' && map_lines[i][j] != '0'
					&& map_lines[i][j] != 'E' && map_lines[i][j] != 'P'
					&& map_lines[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_map(t_game *game, char **map_lines)
{
	if (!row_count_check(map_lines, game->height, game->width))
		return (ft_putstr_fd("Error: Incorrect number of rows.\n", 2), 0);
	else if (!column_count_check(map_lines, game->height, game->width))
		return (ft_putstr_fd("Error: Incorrect number of columns.\n", 2), 0);
	else if (!checking_walls(map_lines, game->height, game->width))
		return (ft_putstr_fd("Error: Map isn't properly enclosed.\n", 2), 0);
	else if (!valid_characters(map_lines, game->height, game->width))
		return (ft_putstr_fd("Error: Invalid characters.\n", 2), 0);
	else if (!characters_count_check(map_lines, game->height, game->width, 'E'))
		return (ft_putstr_fd("Error: Map must contain 1 exit 'E'.\n", 2), 0);
	else if (!characters_count_check(map_lines, game->height, game->width, 'P'))
		return (ft_putstr_fd("Error: Map must contain 1 player 'P'.\n", 2), 0);
	else if (!characters_count_check(map_lines, game->height, game->width, 'C'))
		return (ft_putstr_fd("Error: Need at min 1 collectible 'C'.\n", 2), 0);
	return (1);
}
