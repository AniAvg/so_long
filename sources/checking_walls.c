/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:26:06 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/21 13:26:10 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_up_down_walls(char **map_lines, int row_count, int column_count)
{
	int	j;

	j = 0;
	while (j < column_count)
	{
		if (map_lines[0][j] != '1' || map_lines[row_count - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_left_right_walls(char **map_lines, int row_count, int column_count)
{
	int	i;

	i = 0;
	while (i < row_count)
	{
		if (map_lines[i][0] != '1' || map_lines [i][column_count - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	checking_walls(char **map_lines, int row_count, int column_count)
{
	int	result1;
	int	result2;

	result1 = check_up_down_walls(map_lines, row_count, column_count);
	result2 = check_left_right_walls(map_lines, row_count, column_count);
	if (result1 == 1 && result2 == 1)
		return (1);
	return (0);
}
