/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:45:17 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/26 14:46:10 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_no_so(t_game game, t_mlx *mlx)
{
	mlx->texture[0].img = mlx_xpm_file_to_image(mlx->mlx, game.no_path,
			&mlx->texture[0].width,
			&mlx->texture[0].height);
	mlx->texture[0].data = (int *)mlx_get_data_addr(mlx->texture[0].img,
			&mlx->texture[0].bits_per_pixel,
			&mlx->texture[0].line_length,
			&mlx->texture[0].endian);
	mlx->texture[1].img = mlx_xpm_file_to_image(mlx->mlx, game.so_path,
			&mlx->texture[1].width,
			&mlx->texture[1].height);
	mlx->texture[1].data = (int *)mlx_get_data_addr(mlx->texture[1].img,
			&mlx->texture[1].bits_per_pixel,
			&mlx->texture[1].line_length,
			&mlx->texture[1].endian);
}

static void	init_we_ea(t_game game, t_mlx *mlx)
{
	mlx->texture[2].img = mlx_xpm_file_to_image(mlx->mlx, game.we_path,
			&mlx->texture[2].width,
			&mlx->texture[2].height);
	mlx->texture[2].data = (int *)mlx_get_data_addr(mlx->texture[2].img,
			&mlx->texture[2].bits_per_pixel,
			&mlx->texture[2].line_length,
			&mlx->texture[2].endian);
	mlx->texture[3].img = mlx_xpm_file_to_image(mlx->mlx, game.ea_path,
			&mlx->texture[3].width,
			&mlx->texture[3].height);
	mlx->texture[3].data = (int *)mlx_get_data_addr(mlx->texture[3].img,
			&mlx->texture[3].bits_per_pixel,
			&mlx->texture[3].line_length,
			&mlx->texture[3].endian);
}

void	init_texture(t_game game, t_mlx *mlx)
{
	// TODO: Add security if file not found!!
	init_no_so(game, mlx);
	init_we_ea(game, mlx);
}
