/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:56:45 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/20 14:37:47 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_ceiling(t_game game, t_mlx *mlx, unsigned int *y)
{
	unsigned int	x;
	int				offset;

	while (*y < WIN_Y / 2)
	{
		x = 0;
		while (x < WIN_X)
		{
			offset = ((*y) * mlx->image.line_length + x
					* (mlx->image.bits_per_pixel / 8));
			*(unsigned int *)(mlx->image.addr + offset)
				= game.ceiling_hex;
			x++;
		}
		(*y)++;
	}
}

static void	fill_floor(t_game game, t_mlx *mlx, unsigned int *y)
{
	unsigned int	x;
	int				offset;

	while (*y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			offset = ((*y) * mlx->image.line_length + x
					* (mlx->image.bits_per_pixel / 8));
			*(unsigned int *)(mlx->image.addr + offset)
				= game.floor_hex;
			x++;
		}
		(*y)++;
	}
}

void	background(t_game game, t_mlx *mlx)
{
	unsigned int	y;

	y = 0;
	fill_ceiling(game, mlx, &y);
	fill_floor(game, mlx, &y);
}
