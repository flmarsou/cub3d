/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:10:50 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/20 12:14:14 by flmarsou         ###   ########.fr       */
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

static void	store_info(t_game *game, char *line, unsigned int height)
{
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(line);
	if (len > game->file.x)
		game->file.x = len;
	game->file.y = height + 1;
	i = 0;
	while (line[i])
	{
		if (line[i] == N || line[i] == S || line[i] == W || line[i] == E)
		{
			game->file.pos_x = i;
			game->file.pos_y = height;
			game->file.facing = line[i];
		}
		i++;
	}
}

void	store_map(t_game *game, char *line, unsigned int len)
{
	char	**new_map;

	new_map = realloc_arr(game->file.map, len, len + 1);
	new_map[len] = line;
	store_info(game, new_map[len], len);
	game->file.map = new_map;
}
