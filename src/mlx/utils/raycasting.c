/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:53:10 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/26 14:43:19 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_ray(t_game *game)
{
	if (game->ray_dir_x < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->pos_x - game->map_x)
			* game->delta_dist_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->map_x + 1 - game->pos_x)
			* game->delta_dist_x;
	}
	if (game->ray_dir_y < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->pos_y - game->map_y)
			* game->delta_dist_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->map_y + 1 - game->pos_y)
			* game->delta_dist_y;
	}
}

static void	perform_dda(t_game *game)
{
	while (true)
	{
		if (game->side_dist_x < game->side_dist_y)
		{
			game->side_dist_x += game->delta_dist_x;
			game->map_x += game->step_x;
			game->side = 0;
		}
		else
		{
			game->side_dist_y += game->delta_dist_y;
			game->map_y += game->step_y;
			game->side = 1;
		}
		if (game->map[game->map_y][game->map_x] == '1')
			break ;
	}
}

static void	calculate_wall_dist_height(t_game *game)
{
	if (game->side == 0)
		game->perp_wall_dist = (game->map_x - game->pos_x
				+ (1 - game->step_x) / 2) / game->ray_dir_x;
	else
		game->perp_wall_dist = (game->map_y - game->pos_y
				+ (1 - game->step_y) / 2) / game->ray_dir_y;
	game->line_height = (int)(WIN_Y / game->perp_wall_dist);
	game->draw_start = -game->line_height / 2 + WIN_Y / 2;
	game->draw_end = game->line_height / 2 + WIN_Y / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	if (game->draw_end >= WIN_Y)
		game->draw_end = WIN_Y - 1;
}

static void	calculate_wall_side(t_game *game)
{
	if (game->side == 0)
	{
		if (game->ray_dir_x < 0)
			game->texture = 2;
		else
			game->texture = 3;
	}
	else
	{
		if (game->ray_dir_y < 0)
			game->texture = 0;
		else
			game->texture = 1;
	}
}

void	raycasting(t_game *game, t_mlx *mlx)
{
	unsigned int	x;

	x = 0;
	while (x < WIN_X)
	{
		game->camera_x = 2 * x / (float)WIN_X - 1;
		game->ray_dir_x = game->dir_x + game->plane_x * game->camera_x;
		game->ray_dir_y = game->dir_y + game->plane_y * game->camera_x;
		game->delta_dist_x = fabs(1 / game->ray_dir_x);
		game->delta_dist_y = fabs(1 / game->ray_dir_y);
		game->map_x = (int)game->pos_x;
		game->map_y = (int)game->pos_y;
		calculate_ray(game);
		perform_dda(game);
		calculate_wall_dist_height(game);
		calculate_wall_side(game);
		texturing(game, mlx, x);
		x++;
	}
}
