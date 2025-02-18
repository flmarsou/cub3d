/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_stop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:58:10 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/18 13:10:07 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroyer(t_mlx *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->bg.img)
		mlx_destroy_image(mlx->mlx, mlx->bg.img);
}

int	close_game(t_game *game, t_mlx *mlx)
{
	destroyer(mlx);
	free_game_struct(game);
	printf(OK"Game closed!\n");
	exit(0);
}
