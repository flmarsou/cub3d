/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:47:48 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/20 14:47:33 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render(t_game *game, t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	background(*game, mlx);
	raycasting(game, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image.img, 0, 0);
}

static int	handle_keypress(int key, t_data *data)
{
	if (key == KEY_ESC)
		close_game(data);
	else if (key == KEY_ARROW_LEFT)
		rotate(data->game, ROT_SPEED);
	else if (key == KEY_ARROW_RIGHT)
		rotate(data->game, -ROT_SPEED);
	else if (key == KEY_W)
		move(data->game, KEY_W);
	else if (key == KEY_S)
		move(data->game, KEY_S);
	else if (key == KEY_A)
		strafe(data->game, KEY_A);
	else if (key == KEY_D)
		strafe(data->game, KEY_D);
	else
		return (0);
	render(data->game, data->mlx);
	return (0);
}

void	game_loop(t_game *game, t_mlx *mlx)
{
	game->dir_x = -1;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66f;
	init_image(mlx);
	mlx_hook(mlx->win, 2, 1L, handle_keypress, &(t_data){game, mlx});
	mlx_hook(mlx->win, 17, 0L, close_game, &(t_data){game, mlx});
	mlx_loop(mlx->mlx);
}
