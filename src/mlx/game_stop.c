/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_stop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:58:10 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/17 10:09:23 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_game *game)
{
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	free_game_struct(game);
	printf(OK"Game closed!\n");
	exit(0);
}
