/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:29:03 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/25 13:33:44 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_speed(t_mlx *mlx)
{
	float	is_running;

	if (mlx->key_pressed[6])
		is_running = 2;
	else
		is_running = 1;
	if ((mlx->key_pressed[2] && mlx->key_pressed[3])
		|| (mlx->key_pressed[2] && mlx->key_pressed[5])
		|| (mlx->key_pressed[4] && mlx->key_pressed[3])
		|| (mlx->key_pressed[4] && mlx->key_pressed[5]))
		return (MOVE_SPEED / 2 * is_running);
	else
		return (MOVE_SPEED * is_running);
}

void	rotate(t_game *game, float speed)
{
	const float	old_dir_x = game->dir_x;
	const float	old_plane_x = game->plane_x;

	game->dir_x = game->dir_x * cos(speed) - game->dir_y * sin(speed);
	game->dir_y = old_dir_x * sin(speed) + game->dir_y * cos(speed);
	game->plane_x = game->plane_x * cos(speed) - game->plane_y * sin(speed);
	game->plane_y = old_plane_x * sin(speed) + game->plane_y * cos(speed);
}

void	move(t_game *game, int key, float speed)
{
	if (key == KEY_W)
	{
		if (game->map[(int)game->pos_y]
			[(int)(game->pos_x + game->dir_x * speed)] != '1')
			game->pos_x += game->dir_x * speed;
		if (game->map[(int)(game->pos_y + game->dir_y * speed)]
				[(int)game->pos_x] != '1')
			game->pos_y += game->dir_y * speed;
	}
	else if (key == KEY_S)
	{
		if (game->map[(int)game->pos_y]
			[(int)(game->pos_x - game->dir_x * speed)] != '1')
			game->pos_x -= game->dir_x * speed;
		if (game->map[(int)(game->pos_y - game->dir_y * speed)]
				[(int)game->pos_x] != '1')
			game->pos_y -= game->dir_y * speed;
	}
}

void	strafe(t_game *game, int key, float speed)
{
	if (key == KEY_A)
	{
		if (game->map[(int)game->pos_y]
			[(int)(game->pos_x - game->plane_x * speed)] != '1')
			game->pos_x -= game->plane_x * speed;
		if (game->map[(int)(game->pos_y - game->plane_y * speed)]
				[(int)game->pos_x] != '1')
			game->pos_y -= game->plane_y * speed;
	}
	else if (key == KEY_D)
	{
		if (game->map[(int)game->pos_y]
			[(int)(game->pos_x + game->plane_x * speed)] != '1')
			game->pos_x += game->plane_x * speed;
		if (game->map[(int)(game->pos_y + game->plane_y * speed)]
				[(int)game->pos_x] != '1')
			game->pos_y += game->plane_y * speed;
	}
}
