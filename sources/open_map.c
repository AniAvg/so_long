/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:24:18 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/05 16:24:39 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_map_lines(int fd)
{
	char	*tmp;
	char	*line;

	tmp = NULL;
	line = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		line = ft_gnl_strjoin(line, tmp);
		free(tmp);
	}
	return (line);
}

void	open_map(char *path)
{
	int		fd;
	int		row_count;
	int		column_count;
	char	*line;
	char	**map_lines;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_map_lines(fd);
	map_lines = ft_split(line, '\n');
	column_count = ft_strlen(map_lines[0]);
	while (map_lines[row_count])
		row_count++;
	if (!valid_map(map_lines, row_count, column_count))
	{
		free(line);
		free_split(map_lines);
		close(fd);//
		print_error("Error: Validation Error.\n");
	}
	if (!close(fd))
		print_error("Error: Can't close the file.\n");
	free(line);
}
