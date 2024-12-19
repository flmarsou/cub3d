/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:45:23 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/19 08:49:47 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_file(t_game *game)
{
	if (game->file.no_path)
		free(game->file.no_path);
	if (game->file.so_path)
		free(game->file.so_path);
	if (game->file.we_path)
		free(game->file.we_path);
	if (game->file.ea_path)
		free(game->file.ea_path);
	if (game->file.floor.raw)
		free(game->file.floor.raw);
	if (game->file.ceiling.raw)
		free(game->file.ceiling.raw);
}
