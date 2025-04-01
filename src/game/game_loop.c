/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:47:48 by flmarsou          #+#    #+#             */
/*   Updated: 2025/04/01 10:17:47 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	loop(t_data *data)
{
	float	speed;

	speed = get_speed(data->game, data->mlx);
	if (data->mlx->key_pressed[0])
		rotate(data->game, -ROT_SPEED);
	if (data->mlx->key_pressed[1])
		rotate(data->game, ROT_SPEED);
	if (data->mlx->key_pressed[2])
		move(data->game, KEY_W, speed);
	if (data->mlx->key_pressed[3])
		strafe(data->game, KEY_A, speed);
	if (data->mlx->key_pressed[4])
		move(data->game, KEY_S, speed);
	if (data->mlx->key_pressed[5])
		strafe(data->game, KEY_D, speed);
	render(data->game, data->mlx);
	if (data->mlx->frames > 128)
		data->mlx->frames = 0;
	else
		data->mlx->frames++;
	return (0);
}

static int	handle_mouse(int cursor_x, int cursor_y, t_data *data)
{
	(void)cursor_y;
	mlx_mouse_move(data->mlx->mlx, data->mlx->win, WIN_X / 2, WIN_Y / 2);
	if (cursor_x < WIN_X / 2)
		rotate(data->game, -ROT_SPEED * 2.5f);
	if (cursor_x > WIN_X / 2)
		rotate(data->game, ROT_SPEED * 2.5f);
	return (0);
}

void	game_loop(t_game *game, t_mlx *mlx)
{
	t_data	data;

	data.game = game;
	data.mlx = mlx;
	init_image(mlx);
	if (!init_texture(*game, mlx))
		close_game(&data);
	mlx_mouse_hide(mlx->mlx, mlx->win);
	mlx_hook(mlx->win, KEY_PRESS, KEY_PRESS_MASK, handle_keypress, &data);
	mlx_hook(mlx->win, KEY_RELEASE, KEY_RELEASE_MASK, handle_keyrelease, &data);
	mlx_hook(mlx->win, MOTION_NOTIFY, POINTER_MOTION_MASK, handle_mouse, &data);
	mlx_loop_hook(mlx->mlx, loop, &data);
	mlx_hook(mlx->win, DESTROY_NOTIFY, NO_EVENT_MASK, close_game, &data);
	mlx_loop(mlx->mlx);
}
