/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:56:24 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/20 10:41:54 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parsing(int argc, char **argv, t_game *game)
{
	int	fd;

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
