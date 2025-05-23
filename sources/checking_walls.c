/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:21:50 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/22 16:45:38 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
