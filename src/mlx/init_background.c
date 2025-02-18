/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:34:28 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/18 13:17:18 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_ceiling(t_game game, t_mlx *mlx, unsigned int *y)
{
	unsigned int	x;
	int				offset;

	while (*y < WIN_Y / 2)
	{
		x = 0;
		while (x < WIN_X)
		{
			offset = ((*y) * mlx->bg.line_length + x
					* (mlx->bg.bits_per_pixel / 8));
			*(unsigned int *)(mlx->bg.addr + offset)
				= game.ceiling_hex;
			x++;
		}
		(*y)++;
	}
}

void	fill_floor(t_game game, t_mlx *mlx, unsigned int *y)
{
	unsigned int	x;
	int				offset;

	while (*y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			offset = ((*y) * mlx->bg.line_length + x
					* (mlx->bg.bits_per_pixel / 8));
			*(unsigned int *)(mlx->bg.addr + offset)
				= game.floor_hex;
			x++;
		}
		(*y)++;
	}
}

void	init_background(t_game game, t_mlx *mlx)
{
	unsigned int	y;

	mlx->bg.img = mlx_new_image(mlx->mlx, WIN_X, WIN_Y);
	mlx->bg.addr = mlx_get_data_addr(
			mlx->bg.img,
			&mlx->bg.bits_per_pixel,
			&mlx->bg.line_length,
			&mlx->bg.endian);
	y = 0;
	fill_ceiling(game, mlx, &y);
	fill_floor(game, mlx, &y);
}
