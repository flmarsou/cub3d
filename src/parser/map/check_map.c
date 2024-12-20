/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:17:49 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/20 16:03:49 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO: Right Check
static bool	check_sides(t_game *game)
{
	unsigned int	y;

	y = 1;
	while (y < game->file.height)
	{
		printf("%c\n", game->file.map[y][0]);
		if (game->file.map[y][0] != EMPTY
			&& game->file.map[y][0] != WALL)
			return (error_map(4, 0, 0, y));
		y++;
	}
	return (true);
}

static bool	check_top_bottom(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (game->file.map[0][x])
	{
		if (game->file.map[0][x] != EMPTY
			&& game->file.map[0][x] != WALL)
			return (error_map(4, 0, x, 0));
		x++;
	}
	x = 0;
	y = game->file.height;
	while (game->file.map[y][x])
	{
		if (game->file.map[y][x] != EMPTY
			&& game->file.map[y][x] != WALL)
			return (error_map(4, 0, x, y));
		x++;
	}
	return (true);
}

bool	check_map(t_game *game)
{
	if (!check_top_bottom(game) || !check_sides(game))
		return (false);
	return (true);
}
