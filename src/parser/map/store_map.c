/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:10:50 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/20 11:46:20 by flmarsou         ###   ########.fr       */
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

void	store_map(t_game *game, char *line, unsigned int len)
{
	char	**new_map;

	new_map = realloc_arr(game->file.map, len, len + 1);
	new_map[len] = line;
	game->file.map = new_map;
}
