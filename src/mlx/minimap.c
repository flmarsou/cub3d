/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:10:30 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/21 12:17:01 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	debug(unsigned char grid[11][11])
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < 11)
	{
		x = 0;
		while (x < 11)
		{
			if (x == 5 && y == 5)
				printf("\e[1;48;2;0;0;255m   ");
			else if (grid[y][x] == '0')
				printf("\e[1;48;2;100;100;100m   ");
			else if (grid[y][x] == '1')
				printf("\e[1;48;2;255;255;255m   ");
			else
				printf("\e[1;48;2;0;0;0m   ");
			x++;
		}
		printf(RESET"\n");
		y++;
	}
	printf(RESET"\n");
}

static void	fill_grid(t_game game, unsigned char grid[11][11])
{
	unsigned int	y;
	unsigned int	x;
	int				scan_y;
	int				scan_x;

	scan_y = (int)game.pos_y - 5;
	y = 0;
	while (y < 11)
	{
		x = 0;
		scan_x = (int)game.pos_x - 5;
		while (x < 11)
		{
			if (scan_y < 0 || scan_y > (int)game.height || scan_x < 0 || scan_x >= (int)ft_strlen(game.map[scan_y]))
				grid[y][x] = ' ';
			else if (game.map[scan_y][scan_x] == '0')
				grid[y][x] = '0';
			else if (game.map[scan_y][scan_x] == '1')
				grid[y][x] = '1';
			x++;
			scan_x++;
		}
		y++;
		scan_y++;
	}
	grid[5][5] = 'P';
}

void	minimap(t_game game, t_mlx *mlx)
{
	unsigned char	grid[11][11];

	fill_grid(game, grid);
	debug(grid);
}
