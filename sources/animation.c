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
	anim->speed_c++;
    if (anim->speed_c > 10)
	{
        anim->speed_c = 0;
        anim->speed_c++;
		if (anim->index_c == 4)
			anim->index_c = 0;
	}
}

void	enemy_animation(t_anim *anim)
{
	anim->speed_e++;
    if (anim->speed_e > 10)
	{
        anim->speed_e = 0;
        anim->speed_e++;
		if (anim->index_e == 4)
			anim->index_e = 0;
	}
}

int loop_hook(t_game *game)
{
	update_animation(game);
	create_map(game);//es sxal a
	return (0);
}




