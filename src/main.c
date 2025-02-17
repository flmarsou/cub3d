/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:52:48 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/17 10:25:41 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	init_window(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
	{
		printf(ERR"Failed to initialize MLX!");
		return (false);
	}
	game->mlx.win = mlx_new_window(game->mlx.mlx, X_WIN, Y_WIN, WIN_TITLE);
	if (!game->mlx.mlx)
	{
		printf(ERR"Failed to create a window!");
		return (false);
	}
	return (true);
}

static void	init_game_struct(t_game *game)
{
	unsigned int	i;

	i = 0;
	game->file.no_path = NULL;
	game->file.so_path = NULL;
	game->file.we_path = NULL;
	game->file.ea_path = NULL;
	game->file.floor.raw = NULL;
	game->file.floor.r = 0;
	game->file.floor.g = 0;
	game->file.floor.b = 0;
	game->file.ceiling.raw = NULL;
	game->file.ceiling.r = 0;
	game->file.ceiling.g = 0;
	game->file.ceiling.b = 0;
	while (i < 6)
		game->file.check_list[i++] = false;
	game->file.map = NULL;
	game->file.facing = 0;
	game->file.player_found = false;
	game->file.height = 0;
	game->file.pos_x = 0;
	game->file.pos_y = 0;
}

int	main(int argc, char **argv)
{
	t_game			game;

	init_game_struct(&game);
	if (!parsing(argc, argv, &game) || !init_window(&game))
	{
		free_game_struct(&game);
		return (1);
	}
	game_loop(&game);
	return (0);
}
