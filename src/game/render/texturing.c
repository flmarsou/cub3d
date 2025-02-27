/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:58:43 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/27 08:51:14 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	texturing(t_game *game, t_mlx *mlx, unsigned int x)
{
	int		y;
	int		color;
	int		offset;

	calculate_wall_side(game);
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
