/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:29:03 by flmarsou          #+#    #+#             */
/*   Updated: 2025/04/01 10:10:13 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_speed(t_game *game, t_mlx *mlx)
{
	game->speed_multiplier = 1;
	if (mlx->key_pressed[6])
		game->speed_multiplier = RUN_MULTIPLIER;
	else if (mlx->key_pressed[8])
		game->speed_multiplier = CROUCH_MULTIPLIER;
	if ((mlx->key_pressed[2] && mlx->key_pressed[3])
		|| (mlx->key_pressed[2] && mlx->key_pressed[5])
		|| (mlx->key_pressed[4] && mlx->key_pressed[3])
		|| (mlx->key_pressed[4] && mlx->key_pressed[5]))
		return (MOVE_SPEED / 2 * game->speed_multiplier);
	else
		return (MOVE_SPEED * game->speed_multiplier);
}

void	rotate(t_game *game, float spd)
{
	const float	old_dir_x = game->dir_x;
	const float	old_plane_x = game->plane_x;

	game->dir_x = game->dir_x * cos(spd) - game->dir_y * sin(spd);
	game->dir_y = old_dir_x * sin(spd) + game->dir_y * cos(spd);
	game->plane_x = game->plane_x * cos(spd) - game->plane_y * sin(spd);
	game->plane_y = old_plane_x * sin(spd) + game->plane_y * cos(spd);
}

void	move(t_game *game, int key, float spd)
{
	if (key == KEY_W)
	{
		if (game->map[(int)game->pos_y][(int)(game->pos_x + game->dir_x * spd)]
			!= '1' && (game->map[(int)game->pos_y][(int)(game->pos_x
				+ game->dir_x * spd)] != 'D' || game->doors_interact))
			game->pos_x += game->dir_x * spd;
		if (game->map[(int)(game->pos_y + game->dir_y * spd)][(int)game->pos_x]
			!= '1' && (game->map[(int)(game->pos_y + game->dir_y * spd)]
				[(int)game->pos_x] != 'D' || game->doors_interact))
			game->pos_y += game->dir_y * spd;
	}
	else if (key == KEY_S)
	{
		if (game->map[(int)game->pos_y][(int)(game->pos_x - game->dir_x * spd)]
			!= '1' && (game->map[(int)game->pos_y][(int)(game->pos_x
				- game->dir_x * spd)] != 'D' || game->doors_interact))
			game->pos_x -= game->dir_x * spd;
		if (game->map[(int)(game->pos_y - game->dir_y * spd)]
			[(int)game->pos_x] != '1' && (game->map[(int)(game->pos_y
				- game->dir_y * spd)][(int)game->pos_x] != 'D'
					|| game->doors_interact))
			game->pos_y -= game->dir_y * spd;
	}
}

void	strafe(t_game *game, int key, float spd)
{
	if (key == KEY_A)
	{
		if (game->map[(int)game->pos_y][(int)(game->pos_x - game->plane_x
			* spd)] != '1' && (game->map[(int)game->pos_y]
				[(int)(game->pos_x - game->plane_x * spd)] != 'D'
					|| game->doors_interact))
			game->pos_x -= game->plane_x * spd;
		if (game->map[(int)(game->pos_y - game->plane_y * spd)]
			[(int)game->pos_x] != '1' && (game->map[(int)(game->pos_y
				- game->plane_y * spd)][(int)game->pos_x] != 'D'
					|| game->doors_interact))
			game->pos_y -= game->plane_y * spd;
	}
	else if (key == KEY_D)
	{
		if (game->map[(int)game->pos_y][(int)(game->pos_x + game->plane_x
			* spd)] != '1' && (game->map[(int)game->pos_y][(int)(game->pos_x
				+ game->plane_x * spd)] != 'D' || game->doors_interact))
			game->pos_x += game->plane_x * spd;
		if (game->map[(int)(game->pos_y + game->plane_y * spd)]
			[(int)game->pos_x] != '1' && (game->map[(int)(game->pos_y
				+ game->plane_y * spd)][(int)game->pos_x] != 'D'
					|| game->doors_interact))
			game->pos_y += game->plane_y * spd;
	}
}
