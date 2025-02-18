/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:32:04 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/18 13:03:29 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		printf(ERR"Failed to initialize MLX!");
		return (false);
	}
	mlx->win = mlx_new_window(mlx->mlx, WIN_X, WIN_Y, WIN_TITLE);
	if (!mlx->mlx)
	{
		printf(ERR"Failed to create a window!");
		return (false);
	}
	return (true);
}
