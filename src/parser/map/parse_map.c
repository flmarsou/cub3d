/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:09:23 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/19 15:11:02 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



bool	parse_map(int fd, t_game *game)
{
	char			*line;
	unsigned int	line_index;
	unsigned int	is_valid;

	line = get_next_line(fd);
	line_index = 0;
	while (line)
	{
		is_valid = check_map_line(line, game);
		if (is_valid == 0)
			return (free(line), false);
		else if (is_valid == 1)
		{
			set_map(game, line, line_index);
			line_index++;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	return (true);
}
