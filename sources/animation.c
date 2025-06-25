/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavgya@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:28:46 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/25 18:56:43 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectible_animation(t_anim *anim)
{
	anim->speed++;
    if (anim->speed > 700)
	{
        anim->speed = 0;
        anim->index++;
		if (anim->index == 4)
			anim->index = 0;
	}
}

void	enemy_animation(t_anim *anim)
{
	anim->speed++;
    if (anim->speed > 700)
	{
        anim->speed = 0;
        anim->index++;
		if (anim->index == 4)
			anim->index = 0;
	}
}

int loop_hook(void *param)
{
	t_game *game = (t_game *)param;

	collectible_animation(&game->anim);
	enemy_animation(&game->anim);
	create_map(game);//es hnaravor a sxal a
	return (0);
}
