/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:56:24 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/18 14:56:00 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parsing(int argc, char **argv, t_game *game)
{
	int	fd;

	game->bit_flag = 0;
	game->player_found = false;
	game->map = NULL;
	if (!parse_args(argc, argv, &fd))
		return (false);
	printf(OK"Correct Args!\n");
	if (!parse_keys(fd, game))
		return (close(fd), false);
	printf(OK"Correct Keys!\n");
	if (!parse_colors(game))
		return (close(fd), false);
	printf(OK"Correct Colors!\n");
	if (!parse_map(fd, game))
		return (close(fd), false);
	printf(OK"Correct Map!\n");
	return (close(fd), true);
}
