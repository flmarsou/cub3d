/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:52:48 by flmarsou          #+#    #+#             */
/*   Updated: 2025/03/03 09:34:14 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_structs(t_game *game, t_mlx *mlx)
{
	unsigned int	i;

	i = 0;
	game->no_path = NULL;
	game->so_path = NULL;
	game->we_path = NULL;
	game->ea_path = NULL;
	game->floor_raw = NULL;
	game->ceiling_raw = NULL;
	game->map = NULL;
	game->dir_x = -1;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66f;
	game->speed_multiplier = 1;
	while (i < 9)
		mlx->key_pressed[i++] = false;
	mlx->frames = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_mlx	mlx;

	init_structs(&game, &mlx);
	if (!parsing(argc, argv, &game) || !init_window(&mlx))
	{
		free_game_struct(&game);
		return (1);
	}
	game_loop(&game, &mlx);
	return (0);
}
