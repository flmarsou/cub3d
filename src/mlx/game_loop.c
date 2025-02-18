/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:47:48 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/18 13:19:21 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_keypress(int key, t_main *main)
{
	if (key == KEY_ESC)
		close_game(main->game, main->mlx);
	else if (key == KEY_ARROW_LEFT)
	{

	}
	return (0);
}

void	game_loop(t_game *game, t_mlx *mlx)
{
	t_main	main;

	main.game = game;
	main.mlx = mlx;
	init_background(*game, mlx);
	mlx_hook(mlx->win, KEY_PRESS, KEY_PRESS_MASK, handle_keypress, &main);
	mlx_hook(mlx->win, DESTROY_NOTIFY, NO_EVENT_MASK, close_game, game);
	mlx_loop(mlx->mlx);
}
