/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:47:48 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/27 09:59:07 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int	handle_keypress(int key, t_data *data)
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

static int	handle_keyrelease(int key, t_data *data)
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

static int	handle_mouse(int cursor_x, int cursor_y, t_data *data)
{
	(void)cursor_y;
	mlx_mouse_move(data->mlx->mlx, data->mlx->win, WIN_X / 2, WIN_Y / 2);
	if (cursor_x < WIN_X / 2)
		rotate(data->game, ROT_SPEED * 2.5f);
	if (cursor_x > WIN_X / 2)
		rotate(data->game, -ROT_SPEED * 2.5f);
	return (0);
}

void	game_loop(t_game *game, t_mlx *mlx)
{
	t_data	data;

	data.game = game;
	data.mlx = mlx;
	init_image(mlx);
	init_texture(*game, mlx);
	mlx_mouse_hide(mlx->mlx, mlx->win);
	mlx_hook(mlx->win, KEY_PRESS, KEY_PRESS_MASK, handle_keypress, &data);
	mlx_hook(mlx->win, KEY_RELEASE, KEY_RELEASE_MASK, handle_keyrelease, &data);
	mlx_hook(mlx->win, MOTION_NOTIFY, POINTER_MOTION_MASK, handle_mouse, &data);
	mlx_loop_hook(mlx->mlx, loop, &data);
	mlx_hook(mlx->win, DESTROY_NOTIFY, NO_EVENT_MASK, close_game, &data);
	mlx_loop(mlx->mlx);
}
