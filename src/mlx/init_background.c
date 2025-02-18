/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:34:28 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/18 10:50:51 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_ceiling(t_game *game, unsigned int *y)
{
	unsigned int	x;
	int				offset;

	while (*y < WIN_Y / 2)
	{
		x = 0;
		while (x < WIN_X)
		{
			offset = ((*y) * game->mlx.bg.line_length + x
					* (game->mlx.bg.bits_per_pixel / 8));
			*(unsigned int *)(game->mlx.bg.addr + offset)
				= game->file.ceiling_hex;
			x++;
		}
		(*y)++;
	}
}

void	fill_floor(t_game *game, unsigned int *y)
{
	unsigned int	x;
	int				offset;

	while (*y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			offset = ((*y) * game->mlx.bg.line_length + x
					* (game->mlx.bg.bits_per_pixel / 8));
			*(unsigned int *)(game->mlx.bg.addr + offset)
				= game->file.floor_hex;
			x++;
		}
		(*y)++;
	}
}

void	init_background(t_game *game)
{
	unsigned int	y;

	game->mlx.bg.img = mlx_new_image(game->mlx.mlx, WIN_X, WIN_Y);
	game->mlx.bg.addr = mlx_get_data_addr(
			game->mlx.bg.img,
			&game->mlx.bg.bits_per_pixel,
			&game->mlx.bg.line_length,
			&game->mlx.bg.endian);
	y = 0;
	fill_ceiling(game, &y);
	fill_floor(game, &y);
}
