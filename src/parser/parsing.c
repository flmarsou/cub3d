/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:56:24 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/17 13:56:41 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parsing(int argc, char **argv, t_game *game)
{
	int	fd;

	if (!check_args(argc, argv, &fd))
		return (false);
	if (!check_keys(&fd, game))
		return (false);
	if (!check_colors(game))
		return (false);
	return (true);
}
