/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:29:03 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/24 13:08:05 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_game *game, float speed)
{
	const float	old_dir_x = game->dir_x;
	const float	old_plane_x = game->plane_x;

	game->dir_x = game->dir_x * cos(speed) - game->dir_y * sin(speed);
	game->dir_y = old_dir_x * sin(speed) + game->dir_y * cos(speed);
	game->plane_x = game->plane_x * cos(speed) - game->plane_y * sin(speed);
	game->plane_y = old_plane_x * sin(speed) + game->plane_y * cos(speed);
}

void	move(t_game *game, int key)
{
	if (key == KEY_W)
	{
		if (game->map[(int)game->pos_y][(int)(game->pos_x + game->dir_x * MOVE_SPEED)] != '1')
			game->pos_x += game->dir_x * MOVE_SPEED;
		if (game->map[(int)(game->pos_y + game->dir_y * MOVE_SPEED)][(int)game->pos_x] != '1')
			game->pos_y += game->dir_y * MOVE_SPEED;
	}
	else if (key == KEY_S)
	{
		if (game->map[(int)game->pos_y][(int)(game->pos_x - game->dir_x * MOVE_SPEED)] != '1')
			game->pos_x -= game->dir_x * MOVE_SPEED;
		if (game->map[(int)(game->pos_y - game->dir_y * MOVE_SPEED)][(int)game->pos_x] != '1')
			game->pos_y -= game->dir_y * MOVE_SPEED;
	}
}

void	strafe(t_game *game, int key)
{
	if (key == KEY_A)
	{
		if (game->map[(int)game->pos_y][(int)(game->pos_x - game->plane_x * MOVE_SPEED)] != '1')
			game->pos_x -= game->plane_x * MOVE_SPEED;
		if (game->map[(int)(game->pos_y - game->plane_y * MOVE_SPEED)][(int)game->pos_x] != '1')
			game->pos_y -= game->plane_y * MOVE_SPEED;
	}
	else if (key == KEY_D)
	{
		if (game->map[(int)game->pos_y][(int)(game->pos_x + game->plane_x * MOVE_SPEED)] != '1')
			game->pos_x += game->plane_x * MOVE_SPEED;
		if (game->map[(int)(game->pos_y + game->plane_y * MOVE_SPEED)][(int)game->pos_x] != '1')
		game->pos_y += game->plane_y * MOVE_SPEED;
	}
}
