/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:17:49 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/26 09:12:22 by flmarsou         ###   ########.fr       */
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
	while (y <= game->height - 1)
	{
		x = 1;
		while (game->map[y][x + 1])
		{
			if (game->map[y][x] == '0'
				|| game->map[y][x] == 'N' || game->map[y][x] == 'S'
				|| game->map[y][x] == 'W' || game->map[y][x] == 'E')
			{
				if (game->map[y + 1][x] == ' '
					|| game->map[y - 1][x] == ' '
					|| game->map[y][x + 1] == ' '
					|| game->map[y][x - 1] == ' ')
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
	while (game->map[y])
	{
		if ((game->map[y][0] != ' ' && game->map[y][0] != '1') || (game->map[y][ft_strlen(game->map[y]) - 1] != ' '
			&& game->map[y][ft_strlen(game->map[y]) - 1] != '1'))
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
	while (game->map[0][x])
	{
		if (game->map[0][x] != ' ' && game->map[0][x] != '1')
			return (error_map(4, 0, x, 0));
		x++;
	}
	x = 0;
	y = game->height;
	while (game->map[y][x])
	{
		if (game->map[y][x] != ' ' && game->map[y][x] != '1')
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
