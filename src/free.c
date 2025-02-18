/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:45:23 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/18 10:49:02 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game_struct(t_game *game)
{
	unsigned int	i;

	i = 0;
	if (game->file.no_path)
		free(game->file.no_path);
	if (game->file.so_path)
		free(game->file.so_path);
	if (game->file.we_path)
		free(game->file.we_path);
	if (game->file.ea_path)
		free(game->file.ea_path);
	if (game->file.floor_raw)
		free(game->file.floor_raw);
	if (game->file.ceiling_raw)
		free(game->file.ceiling_raw);
	if (game->file.map)
	{
		while (game->file.map[i])
			free(game->file.map[i++]);
		free(game->file.map);
	}
}
