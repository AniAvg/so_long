/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:05:58 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/17 16:38:46 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int		is_file_empty()
// {
// 	if ()
// }

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

char	**open_map(t_game *game, char *path)
{
	int		fd;
	char	*line;
	char	**map_lines;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error("Error: Can't open file.\n");
	line = get_map_lines(fd);
	map_lines = ft_split(line, '\n');
	game->width = ft_strlen(map_lines[0]);
	while (map_lines[game->height])
		game->height++;
	if (!valid_map(game, map_lines))
	{
		free(line);
		free_split(map_lines);
		close(fd);
		exit(1);
	}
	if (close(fd) < 0)
		print_error("Error: Can't close the file.\n");
	free(line);
	return (map_lines);
}
