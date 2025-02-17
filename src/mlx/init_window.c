/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:32:04 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/17 15:34:05 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_window(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
	{
		printf(ERR"Failed to initialize MLX!");
		return (false);
	}
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIN_X, WIN_Y, WIN_TITLE);
	if (!game->mlx.mlx)
	{
		printf(ERR"Failed to create a window!");
		return (false);
	}
	return (true);
}
