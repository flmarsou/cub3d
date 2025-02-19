/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:47:48 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/19 15:31:30 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_keypress(int key, t_data *data)
{
	if (key == KEY_ESC)
		close_game(data);
	else if (key == KEY_ARROW_LEFT)
		data->game->dir_x -= 0.1f;
	else if (key == KEY_ARROW_RIGHT)
		data->game->dir_x += 0.1f;
	else if (key == KEY_W)
		data->game->pos_x += 0.1f;
	else if (key == KEY_S)
		data->game->pos_x -= 0.1f;
	else if (key == KEY_A)
		data->game->pos_y -= 0.1f;
	else if (key == KEY_D)
		data->game->pos_y += 0.1f;
	else
		return (0);
	//printf("Player Pos -> X: %f Y: %f\n", data->game->pos_x, data->game->pos_y);
	//printf("Player Dir -> X: %f\n", data->game->dir_x);
	raycasting(data); // TODO: Add background into image
	return (0);
}

void	game_loop(t_game *game, t_mlx *mlx)
{
	game->dir_x = 0;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66f;
	mlx_hook(mlx->win, KEY_PRESS, KEY_PRESS_MASK, handle_keypress, &(t_data){game, mlx});
	mlx_hook(mlx->win, DESTROY_NOTIFY, NO_EVENT_MASK, close_game, &(t_data){game, mlx});
	mlx_loop(mlx->mlx);
}
