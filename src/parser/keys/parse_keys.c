/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:01:58 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/18 15:12:15 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_keys(int fd, t_game *game)
{
	char			*line;
	unsigned int	key;
	unsigned int	len;

	line = get_next_line(fd);
	while (line)
	{
		key = get_key(line);
		if (key > 0)
		{
			if (!found_key(key, game) || !check_key(key, line, &len))
				return (free(line), false);
			set_key(key, line, len, game);
		}
		if (check_list(game, false) == true)
		{
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (check_list(game, true));
}
