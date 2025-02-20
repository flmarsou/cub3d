/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:29:03 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/20 14:46:45 by flmarsou         ###   ########.fr       */
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
		game->pos_x += game->dir_x * MOVE_SPEED;
		game->pos_y += game->dir_y * MOVE_SPEED;
	}
	else if (key == KEY_S)
	{
		game->pos_x -= game->dir_x * MOVE_SPEED;
		game->pos_y -= game->dir_y * MOVE_SPEED;
	}
}

void	strafe(t_game *game, int key)
{
	if (key == KEY_A)
	{
		game->pos_x -= game->plane_x * MOVE_SPEED;
		game->pos_y -= game->plane_y * MOVE_SPEED;
	}
	else if (key == KEY_D)
	{
		game->pos_x += game->plane_x * MOVE_SPEED;
		game->pos_y += game->plane_y * MOVE_SPEED;
	}
}
