/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:01:58 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/19 10:46:05 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_keys(int fd, t_game *game)
{
	char			*line;
	unsigned int	key;
	unsigned int	len;
	unsigned int	i;

	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		key = is_key(line);
		if (key == 0)
			return (free(line), printf(ERR"Unrecognized line %u!\n", i), false);
		if (!found_key(key, game) || !check_key(key, line, &len))
			return (free(line), false);
		set_key(key, line, len, game);
		if (check_list(game, false))
		{
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (check_list(game, true));
}
