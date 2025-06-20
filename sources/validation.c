/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:05:58 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/20 14:19:21 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_game *game)
{
	int		i;
	int		j;
	char	**map_copy;

	i = 0;
	map_copy = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!map_copy)
		return (NULL);
	while (i < game->height)
	{
		j = 0;
		map_copy[i] = (char *)malloc(sizeof(char) * (game->width + 1));
		if (!map_copy[i])
		// {
		// 	free(map_copy[i]);
		// 	return (NULL);
		// }
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
		}
		while (j < game->width)
		{
			map_copy[i][j] = game->map[i][j];
			j++;
		}
		map_copy[i][j] = '\0';
		i++;
	}
	map_copy[i] = '\0';
	return (map_copy);
}

void	flood_fill(char **map, t_game *game, int x, int y, int new_color)
{
	if (x < 0 || y < 0 || x >= game->height || y >= game->width)
		return ;
	if (map[x][y] == 'C' || map[x][y] == 'P')
		map[x][y] = '0';
	if (map[x][y] == '1' || map[x][y] == new_color)
		return ;
	if (map[x][y] == 'E')
	{
		map[x][y] = '1';
		return ;
	}
	if (map[x][y] != '0')
		return ;
	map[x][y] = new_color;
	flood_fill(map, game, x - 1, y, new_color);
	flood_fill(map, game, x + 1, y, new_color);
	flood_fill(map, game, x, y -1, new_color);
	flood_fill(map, game, x, y + 1, new_color);
}

int	is_walls_correct(t_game *game)
{
	int		i;
	int		j;
	char	**map_copy;

	i = 0;
	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	player_position(game);
	flood_fill(map_copy, game, game->player_y, game->player_x, 'F');
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (map_copy[i][j] != 'F' && map_copy[i][j] != '1')
			{
				free_map(map_copy);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_map(map_copy);
	return (1);
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
		if (!tmp || tmp[0] == '\n')
		{
			get_next_line(-1);
			if (!tmp)
				break ;
			free(tmp);
			free(line);
			return ("\n");
		}
		if (!line)
			line = ft_gnl_strdup(tmp);
		else
			line = ft_gnl_strjoin(line, tmp);
		free(tmp);
	}
	return (line);
}

char	**open_map(t_game *game, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(game);
		print_error("Error: Can't open file.\n");
	}
	line = get_map_lines(fd);
	if (!line || !*line)
	{
		close(fd);
		free(line);
		free(game);
		print_error("Error: Map file is empty.\n");
	}
	if (*line == '\n')
	{
		close(fd);
		//free(line);
		free(game);
		print_error("Error: Invalid map format.\n");
	}
	game->map = ft_split(line, '\n');
	if (!game->map)
	{
		close(fd);
		free(line);
		free_map(game->map);
		free(game);
		print_error("Error: Invalid map format or malloc error.\n");
	}
	game->width = ft_strlen(game->map[0]);
	while (game->map[game->height])
		game->height++;
	if (!valid_map(game, game->map))
	{
		close(fd);
		free(line);
		free_map(game->map);
		free(game);
		exit(1);
	}
	if (!is_walls_correct(game))
	{
		close(fd);
		free(line);
		free_map(game->map);
		free(game);
		print_error("Error: Map has unreachable collectibles or exit.\n");
	}
	close(fd);
	free(line);
	return (game->map);
}
