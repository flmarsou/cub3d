/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:47:48 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/17 10:10:34 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_loop(t_game *game)
{
	mlx_hook(game->mlx.win, KEY_PRESS, KEY_PRESS_MASK, handle_keypress, game);
	mlx_hook(game->mlx.win, DESTROY_NOTIFY, NO_EVENT_MASK, close_game, game);
	mlx_loop(game->mlx.mlx);
}
