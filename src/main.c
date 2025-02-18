/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:52:48 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/18 13:15:43 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_game_struct(t_game *game)
{
	game->bit_flag = 0;
	game->map = NULL;
	game->player_found = false;
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_mlx	mlx;

	init_game_struct(&game);
	if (!parsing(argc, argv, &game) || !init_window(&mlx))
	{
		free_game_struct(&game);
		return (1);
	}
	game_loop(&game, &mlx);
	return (0);
}
