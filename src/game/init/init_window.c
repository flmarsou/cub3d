/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:32:04 by flmarsou          #+#    #+#             */
/*   Updated: 2025/03/31 11:59:00 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		printf(ERR"Failed to initialize MLX!\n"RESET);
		return (false);
	}
	mlx->win = mlx_new_window(mlx->mlx, WIN_X, WIN_Y, WIN_TITLE);
	if (!mlx->win)
	{
		printf(ERR"Failed to create a window!\n"RESET);
		return (false);
	}
	return (true);
}
