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
	char	*line;
	char	**map_lines;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_map_lines(fd);
	map_lines = ft_split(line, '\n');
	free(line);
}
