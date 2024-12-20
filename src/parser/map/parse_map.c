/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:09:23 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/20 15:42:20 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	check_map_line(t_game *game, char *line)
{
	unsigned int	i;

	if (!line || *line == '\n' || *line == '\0')
		return (2);
	i = 0;
	while (line[i])
	{
		if (!ft_ismap(line[i]))
			return (error_map(1, line[i], 0, 0));
		if (!game->file.player_found && (line[i] == N || line[i] == S
				|| line[i] == W || line[i] == E))
			game->file.player_found = true;
		else if (game->file.player_found && (line[i] == N || line[i] == S
				|| line[i] == W || line[i] == E))
			return (error_map(2, 0, 0, 0));
		i++;
	}
	return (1);
}

bool	read_map(int fd, t_game *game)
{
	char			*line;
	unsigned int	line_index;
	unsigned int	is_valid;

	line = get_next_line(fd);
	line_index = 0;
	while (line)
	{
		is_valid = check_map_line(game, line);
		if (is_valid == 0)
			return (free(line), false);
		else if (is_valid == 1)
		{
			store_map(game, line, line_index);
			line_index++;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	if (!game->file.player_found)
		return (error_map(3, 0, 0, 0));
	return (true);
}

bool	parse_map(int fd, t_game *game)
{
	if (!read_map(fd, game))
		return (false);
	if (!check_map(game))
		return (false);
	return (true);
}
