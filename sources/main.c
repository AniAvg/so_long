/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:33:17 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/02 18:27:09 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;

	if (argc > 2)
		print_error("Wrong Arguments.\nUsage: ./so_long path\n");
	if (!valid_path(argv[1]))
		print_error("Invalid path.");
	open_map(argv[1]);
	mlx = mlx_init();
	return (0);
}
