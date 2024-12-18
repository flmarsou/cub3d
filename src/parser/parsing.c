/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:56:24 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/18 15:14:46 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parsing(int argc, char **argv, t_game *game)
{
	int	fd;

	if (!parse_args(argc, argv, &fd))
		return (false);
	if (!parse_keys(fd, game))
		return (close(fd), false);
	if (!parse_colors(game))
		return (close(fd), false);
	if (!parse_map(fd, game))
		return (close(fd), false);
	return (close(fd), true);
}
