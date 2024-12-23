/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:17:49 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/23 14:07:12 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Checks if all '0' are fully enclosed by '1', with no adjacent ' '.
// Skips top/botttom lines, and rightmost/leftmost characters.
static bool	check_closed(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	y = 1;
	while (y <= game->file.height - 1)
	{
		x = 1;
		while (game->file.map[y][x + 1])
		{
			if (game->file.map[y][x] == GROUND)
			{
				if (game->file.map[y + 1][x] == EMPTY
					|| game->file.map[y - 1][x] == EMPTY
					|| game->file.map[y][x + 1] == EMPTY
					|| game->file.map[y][x - 1] == EMPTY)
				return (error_map(4, 0, x, y + 1));
			}
			x++;
		}
		y++;
	}
	return (true);
}

// Checks if the leftmost and rightmost characters of each row are '1' or ' '.
static bool	check_sides(t_game *game)
{
	unsigned int	y;

	y = 0;
	while (game->file.map[y])
	{
		if ((game->file.map[y][0] != EMPTY
			&& game->file.map[y][0] != WALL)
			|| (game->file.map[y][ft_strlen(game->file.map[y]) - 1] != EMPTY
			&& game->file.map[y][ft_strlen(game->file.map[y]) - 1] != WALL))
			return (error_map(4, 0, 0, y));
		y++;
	}
	return (true);
}

// Checks if the top and bottom rows consist only of '1' or ' ' characters.
static bool	check_top_bottom(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (game->file.map[0][x])
	{
		if (game->file.map[0][x] != EMPTY && game->file.map[0][x] != WALL)
			return (error_map(4, 0, x, 0));
		x++;
	}
	x = 0;
	y = game->file.height;
	while (game->file.map[y][x])
	{
		if (game->file.map[y][x] != EMPTY && game->file.map[y][x] != WALL)
			return (error_map(4, 0, x, y));
		x++;
	}
	return (true);
}

bool	check_map(t_game *game)
{
	if (!check_top_bottom(game))
		return (false);
	if (!check_sides(game))
		return (false);
	if (!check_closed(game))
		return (false);
	return (true);
}
