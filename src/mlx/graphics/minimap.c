/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:10:30 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/24 12:28:06 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_cell(t_mlx *mlx, unsigned int cell_x, unsigned int cell_y,
		int color)
{
	int				offset;
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < CELL_SIZE)
	{
		x = 0;
		while (x < CELL_SIZE)
		{
			offset = ((cell_y * CELL_SIZE + y)
					* mlx->image.line_length
					+ (cell_x * CELL_SIZE + x)
					* (mlx->image.bits_per_pixel / 8));
			*(unsigned int *)(mlx->image.addr + offset) = color;
			x++;
		}
		y++;
	}
}

static void	fill_grid(t_game game,
		unsigned char grid[MINIMAP_SIZE][MINIMAP_SIZE],
		unsigned int x, unsigned int y)
{
	int				scan_y;
	int				scan_x;

	scan_y = (int)game.pos_y - MINIMAP_SIZE / 2;
	while (++y < MINIMAP_SIZE)
	{
		x = -1;
		scan_x = (int)game.pos_x - MINIMAP_SIZE / 2;
		while (++x < MINIMAP_SIZE)
		{
			if (scan_y < 0 || scan_y > (int)game.height || scan_x < 0
				|| scan_x >= (int)ft_strlen(game.map[scan_y])
				|| game.map[scan_y][scan_x] == ' ')
				grid[y][x] = ' ';
			else if (game.map[scan_y][scan_x] == '0')
				grid[y][x] = '0';
			else if (game.map[scan_y][scan_x] == '1')
				grid[y][x] = '1';
			else
				grid[y][x] = '2';
			scan_x++;
		}
		scan_y++;
	}
	grid[MINIMAP_SIZE / 2][MINIMAP_SIZE / 2] = 'P';
}

void	minimap(t_game game, t_mlx *mlx)
{
	unsigned char	grid[MINIMAP_SIZE][MINIMAP_SIZE];
	unsigned int	cell_y;
	unsigned int	cell_x;
	int				color;

	fill_grid(game, grid, -1, -1);
	cell_y = 0;
	while (cell_y < MINIMAP_SIZE)
	{
		cell_x = 0;
		while (cell_x < MINIMAP_SIZE)
		{
			if (grid[cell_y][cell_x] == '0')
				color = 0xFFFFFF;
			else if (grid[cell_y][cell_x] == '1')
				color = 0x808080;
			else if (grid[cell_y][cell_x] == ' ')
				color = 0x000000;
			else
				color = 0x0000FF;
			draw_cell(mlx, cell_x, cell_y, color);
			cell_x++;
		}
		cell_y++;
	}
}
