/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:52:48 by flmarsou          #+#    #+#             */
/*   Updated: 2025/04/01 10:22:54 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_dir(t_game *game)
{
	if (game->facing == 'N')
	{
		game->dir_y = -1;
		game->plane_x = 0.66;
	}
	else if (game->facing == 'S')
	{
		game->dir_y = 1;
		game->plane_x = -0.66;
	}
	else if (game->facing == 'E')
	{
		game->dir_x = 1;
		game->plane_y = 0.66;
	}
	else if (game->facing == 'W')
	{
		game->dir_x = -1;
		game->plane_y = -0.66;
	}
}

static void	init_structs(t_game *game, t_mlx *mlx)
{
	unsigned int	i;

	i = 0;
	game->no_path = NULL;
	game->so_path = NULL;
	game->we_path = NULL;
	game->ea_path = NULL;
	game->d_path = NULL;
	game->has_doors = false;
	game->floor_raw = NULL;
	game->ceiling_raw = NULL;
	game->map = NULL;
	game->dir_x = 0;
	game->dir_y = 0;
	game->plane_y = 0;
	game->plane_x = 0;
	game->speed_multiplier = 1;
	while (i < 9)
		mlx->key_pressed[i++] = false;
	mlx->frames = 0;
	game->doors_interact = false;
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
	init_dir(&game);
	game_loop(&game, &mlx);
	return (0);
}
