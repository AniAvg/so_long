/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavgya@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:28:46 by anavagya          #+#    #+#             */
/*   Updated: 2025/06/27 13:51:41 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectible_animation(t_anim *anim)
{
	anim->speed_c++;
	if (anim->speed_c > 700)
	{
		anim->speed_c = 0;
		anim->index_c++;
		if (anim->index_c == 4)
			anim->index_c = 0;
	}
}

void	enemy_animation(t_anim *anim)
{
	anim->speed_e++;
	if (anim->speed_e > 700)
	{
		anim->speed_e = 0;
		anim->index_e++;
		if (anim->index_e == 4)
			anim->index_e = 0;
	}
}

void	update_animated_images(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->anim.collect[game->anim.index_c].img,
					j * SIZE, i * SIZE);
			else if (game->map[i][j] == 'M')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->anim.enemy[game->anim.index_e].img,
					j * SIZE, i * SIZE);
			j++;
		}
		i++;
	}
}

int	loop_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	collectible_animation(&game->anim);
	enemy_animation(&game->anim);
	update_animated_images(game);
	return (0);
}
