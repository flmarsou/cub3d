/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:53:10 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/19 15:18:58 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cast_ray(t_game *game, t_mlx *mlx, unsigned int x)
{
	//
	// Step 1
	//

	float	camera_x = 2 * x / (float)WIN_X - 1;
	float	ray_dir_x = game->dir_x + game->plane_y * camera_x;
	float	ray_dir_y = game->dir_y + game->plane_y * camera_x;
	//printf("camera_x: %f | ray_dir_x: %f | ray_dir_y: %f\n", camera_x, ray_dir_x, ray_dir_y);

	float	delta_dist_x = fabs(1 / ray_dir_x);
	float	delta_dist_y = fabs(1 / ray_dir_y);
	//printf("delta_dist_x: %f | delta_dist_y: %f\n", delta_dist_x, delta_dist_y);

	float	side_dist_x = 0;
	float	side_dist_y = 0;
	int		step_x = 0;
	int		step_y = 0;
	int		map_x = game->pos_x;
	int		map_y = game->pos_y;

	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (game->pos_x - map_x) * delta_dist_x; // Always Zero
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - game->pos_x) * delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (game->pos_y - map_y) * delta_dist_y; // Always Zero
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - game->pos_y) * delta_dist_y;
	}
	//printf("step_x: %d | side_dist_x: %f | side_dist_y: %f\n", step_x, side_dist_x, side_dist_y);

	//
	// Step 2
	//

	int		hit = 0;
	int		side = 0;

	while (hit == 0)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}
		if (game->map[map_y][map_x] && game->map[map_y][map_x] == '1')
			hit = 1;
	}

	//
	// Step 3
	//

	float	perp_wall_dist= 0;

	if (side == 0)
		perp_wall_dist = (map_x - game->pos_x + (1 - step_x) / 2) / ray_dir_x;
	else
		perp_wall_dist = (map_y - game->pos_y + (1 - step_y) / 2) / ray_dir_y;
	//printf("perp_wall_dist: %f\n", perp_wall_dist);

	//
	// Step 4
	//

	int		line_height = (int)(WIN_X / perp_wall_dist);
	int		draw_start = -line_height / 2 + WIN_X / 2;
	if (draw_start < 0)
		draw_start = 0;
	int		draw_end = line_height / 2 + WIN_X / 2;
	if (draw_end >= WIN_X)
		draw_end = WIN_X - 1;
	//printf("line_height: %d | draw_start: %d | draw_end: %d\n", line_height, draw_start, draw_end);

	//
	// Step 5
	//
	int		color;

	if (side == 1)
		color = 0xFF0000;
	else
		color = 0x00FF00;

	//printf("color: %X\n", color);

	//
	// Step 6
	//
	unsigned int	y = 0;

	while (y < WIN_Y)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
		y++;
	}
}

void	raycasting(t_data *data)
{
	unsigned int	x;

	x = 0;
	while (x < WIN_X)
	{
		cast_ray(data->game, data->mlx, x);
		x++;
	}
}
