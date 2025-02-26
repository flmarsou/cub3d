/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_stop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:58:10 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/20 14:11:29 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroyer(t_mlx *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->image.img)
		mlx_destroy_image(mlx->mlx, mlx->image.img);
}

int	close_game(t_data *data)
{
	destroyer(data->mlx);
	free_game_struct(data->game);
	printf(OK"Game closed!\n");
	exit(0);
}
