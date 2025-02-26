/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:34:28 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/24 09:26:17 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_image(t_mlx *mlx)
{
	mlx->image.img = mlx_new_image(mlx->mlx, WIN_X, WIN_Y);
	mlx->image.addr = mlx_get_data_addr(
			mlx->image.img,
			&mlx->image.bits_per_pixel,
			&mlx->image.line_length,
			&mlx->image.endian);
}
