/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:05:58 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/18 17:46:56 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int row_count, int column_count)
{
	int	i;
	int	j;

	i = 1;
	while (i < row_count)
	{
		j = 1;
		while (j < column_count || map[i][j] != '1')
		{
			map[i][j] = '6';
			j++;
		}
		i++;
	}
}
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
	//char	**map_lines;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error("Error: Can't open file.\n");
	line = get_map_lines(fd);
	if (!line || !*line)
	{
		free(line);
		close(fd);
		print_error("Error: Map file is empty.\n");
	}
	game->map = ft_split(line, '\n');
	if (!game->map || !game->map[0] || !game->map[0][0])
	{
		free(line);
		free_split(game->map);
		close(fd);
		print_error("Error: Invalid map format.\n");
	}
	game->width = ft_strlen(game->map[0]);
	while (game->map[game->height])
		game->height++;
	if (!valid_map(game, game->map))
	{
		free(line);
		free_split(game->map);
		close(fd);
		exit(1);
	}
	if (close(fd) < 0)
		print_error("Error: Can't close the file.\n");
	free(line);
	return (game->map);
}
