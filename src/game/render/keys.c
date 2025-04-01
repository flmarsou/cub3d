/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:13:47 by flmarsou          #+#    #+#             */
/*   Updated: 2025/04/01 10:16:33 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	door_key(t_data *data)
{
	if (!data->game->doors_interact)
		data->game->doors_interact = true;
	else if (data->game->doors_interact)
		data->game->doors_interact = false;
}

int	handle_keypress(int key, t_data *data)
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
	if (key == KEY_E)
		door_key(data);
	return (0);
}

int	handle_keyrelease(int key, t_data *data)
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
