/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:03:12 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/13 15:57:16 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_path(char *path)
{
	char	*str;

	if (!path)
		return (0);
	if (ft_strchr(path, ' '))
		return (0);
	str = ft_strrchr(path, '.');
	if (!str || ft_strlen(str) > 4)
		return (0);
	if (ft_strncmp(str, ".ber", 4) != 0)
		return (0);
	return (1);
}
