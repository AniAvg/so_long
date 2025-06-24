/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavgya@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:28:46 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/24 14:50:33 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectible_animation(t_collect *collect)
{
	collect->counter++;
    if (collect->counter >= collect->anim_speed)
	{
        collect->counter = 0;
        collect->index = (collect->index + 1) % 4;
	}
	collect->img = collect->collect_img[collect->index];
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

void	enemy_animation(t_enemy *enemy)
{
	if (enemy->index == 4)
		enemy->index = 0;
	enemy->index++;
	enemy->img = enemy->enemy_img[enemy->index];
	enemy->index = (enemy->index + 1) % 4;
}




