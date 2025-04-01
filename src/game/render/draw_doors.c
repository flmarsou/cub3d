/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:58:43 by flmarsou          #+#    #+#             */
/*   Updated: 2025/04/01 09:56:47 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	texture_frame(unsigned char frame, t_game *game)
{
	if (frame >= 0 && frame <= 64)
		game->texture = 4;
	else if (frame >= 64 && frame <= 128)
		game->texture = 5;
	else if (frame >= 128 && frame <= 192)
		game->texture = 6;
	else
		game->texture = 7;
}

static int	calculate_texture_x(t_game game, t_mlx mlx)
{
	float	wall_x;
	int		texture_x;

	if (game.side == 0)
		wall_x = game.pos_y + game.perp_wall_dist * game.ray_dir_y;
	else
		wall_x = game.pos_x + game.perp_wall_dist * game.ray_dir_x;
	wall_x -= floorf(wall_x);
	texture_x = (int)(wall_x * (float)mlx.texture[game.texture].width);
	if (game.side == 0 && game.ray_dir_x > 0)
		texture_x = mlx.texture[game.texture].width - texture_x - 1;
	if (game.side == 1 && game.ray_dir_y < 0)
		texture_x = mlx.texture[game.texture].width - texture_x - 1;
	return (texture_x);
}

void	draw_doors(t_game *game, t_mlx *mlx, unsigned int x,
	unsigned char frame)
{
	int		y;
	int		color;
	int		offset;

	texture_frame(frame, game);
	game->texture_x = calculate_texture_x(*game, *mlx);
	game->step = (float)mlx->texture[game->texture].height / game->line_height;
	game->texture_pos = (game->draw_start - WIN_Y / 2 + game->line_height / 2)
		* game->step;
	y = game->draw_start;
	while (y < game->draw_end)
	{
		game->texture_y = (int)game->texture_pos
			% (mlx->texture[game->texture].height - 1);
		game->texture_pos += game->step;
		color = mlx->texture[game->texture].data[game->texture_y
			* mlx->texture[game->texture].width + game->texture_x];
		offset = (y * mlx->image.line_length + x
				* (mlx->image.bits_per_pixel / 8));
		*(unsigned int *)(mlx->image.addr + offset) = color;
		y++;
	}
}
