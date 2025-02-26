/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:47:48 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/26 09:55:48 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render(t_game *game, t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	background(*game, mlx);
	raycasting(game, mlx);
	if (mlx->key_pressed[7] && WIN_X > CELL_COUNT * CELL_SIZE && WIN_Y > CELL_COUNT * CELL_SIZE)
		minimap(*game, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image.img, 0, 0);
}

static int	keypress(int key, t_data *data)
{
	if (key == KEY_ESC)
		close_game(data);
	if (key == KEY_ARROW_LEFT)
		data->mlx->key_pressed[0] = true;
	if (key == KEY_ARROW_RIGHT)
		data->mlx->key_pressed[1] = true;
	if (key == KEY_W)
		data->mlx->key_pressed[2] = true;
	if (key == KEY_A)
		data->mlx->key_pressed[3] = true;
	if (key == KEY_S)
		data->mlx->key_pressed[4] = true;
	if (key == KEY_D)
		data->mlx->key_pressed[5] = true;
	if (key == KEY_LEFT_SHIFT)
		data->mlx->key_pressed[6] = true;
	if (key == KEY_M && !data->mlx->key_pressed[7])
		data->mlx->key_pressed[7] = true;
	else if (key == KEY_M && data->mlx->key_pressed[7])
		data->mlx->key_pressed[7] = false;
	if (key == KEY_LEFT_CTRL)
		data->mlx->key_pressed[8] = true;
	return (0);
}

static int	keyrelease(int key, t_data *data)
{
	if (key == KEY_ARROW_LEFT)
		data->mlx->key_pressed[0] = false;
	if (key == KEY_ARROW_RIGHT)
		data->mlx->key_pressed[1] = false;
	if (key == KEY_W)
		data->mlx->key_pressed[2] = false;
	if (key == KEY_A)
		data->mlx->key_pressed[3] = false;
	if (key == KEY_S)
		data->mlx->key_pressed[4] = false;
	if (key == KEY_D)
		data->mlx->key_pressed[5] = false;
	if (key == KEY_LEFT_SHIFT)
		data->mlx->key_pressed[6] = false;
	if (key == KEY_LEFT_CTRL)
		data->mlx->key_pressed[8] = false;
	return (0);
}

static int	loop(t_data *data)
{
	float	speed;

	speed = get_speed(data->game, data->mlx);
	if (data->mlx->key_pressed[0])
		rotate(data->game, ROT_SPEED);
	if (data->mlx->key_pressed[1])
		rotate(data->game, -ROT_SPEED);
	if (data->mlx->key_pressed[2])
		move(data->game, KEY_W, speed);
	if (data->mlx->key_pressed[3])
		strafe(data->game, KEY_A, speed);
	if (data->mlx->key_pressed[4])
		move(data->game, KEY_S, speed);
	if (data->mlx->key_pressed[5])
		strafe(data->game, KEY_D, speed);
	render(data->game, data->mlx);
	return (0);
}

void	game_loop(t_game *game, t_mlx *mlx)
{
	t_data	data;

	data.game = game;
	data.mlx = mlx;
	init_image(mlx);
	mlx_hook(mlx->win, 2, 1L, keypress, &data);
	mlx_hook(mlx->win, 3, 2L, keyrelease, &data);
	mlx_loop_hook(mlx->mlx, loop, &data);
	mlx_hook(mlx->win, 17, 0L, close_game, &data);
	mlx_loop(mlx->mlx);
}
