/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavgya@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:24:27 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/27 15:54:51 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_size(t_game *game)
{
	if (game->height > SCREEN_HEIGHT / SIZE
		|| game->width > SCREEN_WIDTH / SIZE)
		return (0);
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

void	parse_map(t_game *game, int fd, char *line)
{
	if (!line || !*line)
	{
		close(fd);
		free(line);
		free(game);
		print_error("Error\nMap file is empty.\n");
	}
	if (*line == '\n')
	{
		close(fd);
		free(game);
		print_error("Error\nInvalid map format.\n");
	}
	game->map = ft_split(line, '\n');
	if (!game->map)
	{
		close(fd);
		free(line);
		free_map(game->map);
		free(game);
		print_error("Error\nInvalid map format or malloc error.\n");
	}
}

void	validate_map(t_game *game, int fd, char *line)
{
	if (!valid_map(game, game->map))
	{
		close(fd);
		free(line);
		free_map(game->map);
		free(game);
		exit(1);
	}
	if (!check_reachability(game))
	{
		close(fd);
		free(line);
		free_map(game->map);
		free(game);
		print_error("Error\nMap has unreachable collectibles or exit.\n");
	}
	if (!map_size(game))
	{
		close(fd);
		free(line);
		free_map(game->map);
		free(game);
		print_error("Error\nMap is too big.\n");
	}
}

char	**load_map(t_game *game, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(game);
		print_error("Error\nCan't open file.\n");
	}
	line = get_map_lines(fd);
	parse_map(game, fd, line);
	game->width = ft_strlen(game->map[0]);
	while (game->map[game->height])
		game->height++;
	validate_map(game, fd, line);
	close(fd);
	free(line);
	return (game->map);
}
