/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:59:22 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/27 09:59:27 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_game *game, t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	background(*game, mlx);
	raycasting(game, mlx);
	if (mlx->key_pressed[7]
		&& WIN_X > CELL_COUNT * CELL_SIZE && WIN_Y > CELL_COUNT * CELL_SIZE)
		minimap(*game, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image.img, 0, 0);
}
