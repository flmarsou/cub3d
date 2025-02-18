/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_stop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:58:10 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/18 11:41:46 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroyer(t_game *game)
{
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	if (game->mlx.bg.img)
		mlx_destroy_image(game->mlx.mlx, game->mlx.bg.img);
}

int	close_game(t_game *game)
{
	destroyer(game);
	free_game_struct(game);
	printf(OK"Game closed!\n");
	exit(0);
}
