/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:10:50 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/26 12:43:57 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**realloc_arr(char **map, unsigned int len, unsigned int new_len)
{
	char			**tmp;
	unsigned int	i;

	tmp = malloc(sizeof(char *) * (new_len + 1));
	if (!tmp)
		exit(1);
	i = 0;
	while (i < len)
	{
		tmp[i] = map[i];
		i++;
	}
	tmp[new_len] = NULL;
	free(map);
	return (tmp);
}

void	store_player_info(t_game *game, char *line, unsigned int line_index)
{
	unsigned int	i;

	i = 0;
	game->height = line_index;
	while (line[i])
	{
		if (line[i] == 'N'
			|| line[i] == 'S'
			|| line[i] == 'W'
			|| line[i] == 'E')
		{
			game->pos_x = (float)i;
			game->pos_y = (float)line_index;
			game->facing = line[i];
		}
		i++;
	}
}

void	store_map(t_game *game, char *line, unsigned int line_index)
{
	char	**new_map;

	new_map = realloc_arr(game->map, line_index, line_index + 1);
	new_map[line_index] = line;
	store_player_info(game, new_map[line_index], line_index);
	game->map = new_map;
}
