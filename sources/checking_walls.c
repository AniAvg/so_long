/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:21:50 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/20 13:07:51 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// 1 1 1 1 1 1 1 
// 1 0 0 0 0 0 1
// 1 0 0 0 0 0 1
// 1 0 0 0 0 0 1
// 1 1 1 1 1 1 1
int	row_count_check(char **map_lines, int row_count, int column_count)
{
	int		i;
	int		j;
	char	*arr;

	i = 0;
	j = 0;
	arr = (char *)malloc(row_count + 2);
	if (!arr)
		return (0);
	while (j < column_count)
	{
		i = 0;
		while (map_lines[i])
		{
			arr[i] = map_lines[i][j];
			i++;
		}
		arr[i] = '\0';
		if (ft_strlen(arr) != row_count)
			return (free(arr), 0);
		free(arr);////
		j++;
	}
	return (1);
}

int	column_count_check(char **map_lines, int row_count, int column_count)
{
	int		i;
	char	*arr;

	i = 0;
	//column_count = ft_strlen(map_lines[i]);
	// while (map_lines[row_count])
	// 	row_count++; 
	while (i < row_count)
	{
		if (ft_strlen(map_lines[i]) != column_count)
			return (0);
		i++;
	}
	return (1);
}

int	check_up_down_walls(char **map_lines, int column_count)
{
	int	j;

	j = 0;
	while (j < column_count)
	{
		if (map_lines[0][j] != '1' || map_lines[column_count][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_left_right_walls(char **map_lines, int row_count)
{
	int	i;

	i = 0;
	while (i < row_count)
	{
		if (map_lines[i][0] != '1' || map_lines [i][row_count] != '1')
			return (0);
		i++;
	}
	return (1);
}
