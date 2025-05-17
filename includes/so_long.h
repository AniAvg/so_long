/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:29:47 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/17 17:58:42 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>

// utils.c
void	print_error(char *str);

// arg_validation.c
int		valid_path(char *path);

// checking_walls.c
int		check_up_down_walls(char **map_lines, int size);
int		check_left_right_walls(char **map_lines, int size);
int		count_check(char **map_lines);

// open_map.c
char	*get_map_lines(int fd);
void	open_map(char *path);

// main.c
#endif