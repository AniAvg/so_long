/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:12:22 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/17 14:02:33 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_path(char *path)
{
	char	*str;

	if (!path)
		return (0);
	str = ft_strrchr(path, '.');
	if (!str || ft_strlen(str) > 4)
		return (0);
	if (ft_strncmp(str, ".ber", 4) != 0)
		return (0);
	return (1);
}
