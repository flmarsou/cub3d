/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:45:17 by flmarsou          #+#    #+#             */
/*   Updated: 2025/03/31 14:45:50 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	init_no_so(t_game game, t_mlx *mlx)
{
	mlx->texture[0].img = mlx_xpm_file_to_image(mlx->mlx, game.no_path,
			&mlx->texture[0].width,
			&mlx->texture[0].height);
	if (!mlx->texture[0].img)
		return (printf(ERR"Texture NO \"%s\" not found!\n"RESET,
				game.no_path), false);
	mlx->texture[0].data = (int *)mlx_get_data_addr(mlx->texture[0].img,
			&mlx->texture[0].bits_per_pixel,
			&mlx->texture[0].line_length,
			&mlx->texture[0].endian);
	printf(OK"Texture NO \"%s\" loaded!\n"RESET, game.no_path);
	mlx->texture[1].img = mlx_xpm_file_to_image(mlx->mlx, game.so_path,
			&mlx->texture[1].width,
			&mlx->texture[1].height);
	if (!mlx->texture[1].img)
		return (printf(ERR"Texture SO \"%s\" not found!\n"RESET,
				game.so_path), false);
	mlx->texture[1].data = (int *)mlx_get_data_addr(mlx->texture[1].img,
			&mlx->texture[1].bits_per_pixel,
			&mlx->texture[1].line_length,
			&mlx->texture[1].endian);
	printf(OK"Texture SO \"%s\" loaded!\n"RESET, game.so_path);
	return (true);
}

static bool	init_we_ea(t_game game, t_mlx *mlx)
{
	mlx->texture[2].img = mlx_xpm_file_to_image(mlx->mlx, game.we_path,
			&mlx->texture[2].width,
			&mlx->texture[2].height);
	if (!mlx->texture[2].img)
		return (printf(ERR"Texture WE \"%s\" not found!\n"RESET,
				game.we_path), false);
	mlx->texture[2].data = (int *)mlx_get_data_addr(mlx->texture[2].img,
			&mlx->texture[2].bits_per_pixel,
			&mlx->texture[2].line_length,
			&mlx->texture[2].endian);
	printf(OK"Texture WE \"%s\" loaded!\n"RESET, game.we_path);
	mlx->texture[3].img = mlx_xpm_file_to_image(mlx->mlx, game.ea_path,
			&mlx->texture[3].width,
			&mlx->texture[3].height);
	if (!mlx->texture[3].img)
		return (printf(ERR"Texture EA \"%s\" not found!\n"RESET,
				game.ea_path), false);
	mlx->texture[3].data = (int *)mlx_get_data_addr(mlx->texture[3].img,
			&mlx->texture[3].bits_per_pixel,
			&mlx->texture[3].line_length,
			&mlx->texture[3].endian);
	printf(OK"Texture EA \"%s\" loaded!\n"RESET, game.ea_path);
	return (true);
}

static bool	init_d1_d2(t_mlx *mlx)
{
	mlx->texture[4].img = mlx_xpm_file_to_image(mlx->mlx, DOOR_1,
			&mlx->texture[4].width,
			&mlx->texture[4].height);
	if (!mlx->texture[4].img)
		return (printf(ERR"Texture DOOR_1 \"%s\" not found!\n"RESET,
				DOOR_1), false);
	mlx->texture[4].data = (int *)mlx_get_data_addr(mlx->texture[4].img,
			&mlx->texture[4].bits_per_pixel,
			&mlx->texture[4].line_length,
			&mlx->texture[4].endian);
	printf(OK"Texture DOOR_1 \"%s\" loaded!\n"RESET, DOOR_1);
	mlx->texture[5].img = mlx_xpm_file_to_image(mlx->mlx, DOOR_2,
			&mlx->texture[5].width,
			&mlx->texture[5].height);
	if (!mlx->texture[5].img)
		return (printf(ERR"Texture DOOR_2 \"%s\" not found!\n"RESET,
				DOOR_2), false);
	mlx->texture[5].data = (int *)mlx_get_data_addr(mlx->texture[5].img,
			&mlx->texture[5].bits_per_pixel,
			&mlx->texture[5].line_length,
			&mlx->texture[5].endian);
	printf(OK"Texture DOOR_2 \"%s\" loaded!\n"RESET, DOOR_2);
	return (true);
}

static bool	init_d3_d4(t_mlx *mlx)
{
	mlx->texture[6].img = mlx_xpm_file_to_image(mlx->mlx, DOOR_3,
			&mlx->texture[6].width,
			&mlx->texture[6].height);
	if (!mlx->texture[6].img)
		return (printf(ERR"Texture DOOR_3 \"%s\" not found!\n"RESET,
				DOOR_3), false);
	mlx->texture[6].data = (int *)mlx_get_data_addr(mlx->texture[6].img,
			&mlx->texture[6].bits_per_pixel,
			&mlx->texture[6].line_length,
			&mlx->texture[6].endian);
	printf(OK"Texture DOOR_3 \"%s\" loaded!\n"RESET, DOOR_3);
	mlx->texture[7].img = mlx_xpm_file_to_image(mlx->mlx, DOOR_4,
			&mlx->texture[7].width,
			&mlx->texture[7].height);
	if (!mlx->texture[7].img)
		return (printf(ERR"Texture DOOR_4 \"%s\" not found!\n"RESET,
				DOOR_4), false);
	mlx->texture[7].data = (int *)mlx_get_data_addr(mlx->texture[7].img,
			&mlx->texture[7].bits_per_pixel,
			&mlx->texture[7].line_length,
			&mlx->texture[7].endian);
	printf(OK"Texture DOOR_4 \"%s\" loaded!\n"RESET, DOOR_4);
	return (true);
}

bool	init_texture(t_game game, t_mlx *mlx)
{
	if (!init_no_so(game, mlx) || !init_we_ea(game, mlx))
		return (false);
	if (game.has_doors && (!init_d1_d2(mlx) || !init_d3_d4(mlx)))
		return (false);
	return (true);
}
