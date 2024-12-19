/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:53:55 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/19 13:54:06 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	check_map_line(char *line, t_game *game)
{
	unsigned int	i;

	if (!line || *line == '\n' || *line == '\0')
		return (2);
	i = 0;
	while (line[i])
	{
		if (!ft_ismap(line[i]))
			return (printf(ERR"Unrecognized character in map '%c'!\n",
					line[i]), 0);
		if (!game->file.playing_found && (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'W' || line[i] == 'E'))
			game->file.playing_found = true;
		else if (game->file.playing_found && (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'W' || line[i] == 'E'))
			return (printf(ERR"Multiple players found in the map!\n"), 0);
		i++;
	}
	return (1);
}
