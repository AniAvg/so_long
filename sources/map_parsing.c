/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:18:00 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/23 17:20:05 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	characters_count_check(char **map_lines, int row_count, char c)// E P C
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < row_count)
	{
		if (ft_strchr(map_lines[i], c))
			count++;
		i++;
	}
	if (c == 'C' && count < 1)
		return (0);
	else if (count != 1)
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
			if (map_lines[i][j] != '1' || map_lines[i][j] != '0'
				|| map_lines[i][j] != 'E' || map_lines[i][j] != 'P'
				|| map_lines[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
