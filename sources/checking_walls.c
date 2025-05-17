/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:21:50 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/17 17:57:30 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_check(char **map_lines)
{
	int	i;
	int	row_count;
	int	column_count;

	column_count = ft_strlen(map_lines[i]);
	while (map_lines[row_count])
		row_count++;
    // ev ayln
}

int	check_up_down_walls(char **map_lines, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (map_lines[0][j] != '1' || map_lines[size][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_left_right_walls(char **map_lines, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (map_lines[i][0] != '1' || map_lines [i][size] != '1')
			return (0);
		i++;
	}
	return (1);
}
