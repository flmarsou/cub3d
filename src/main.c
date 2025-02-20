/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:52:48 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/20 12:42:04 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_mlx	mlx;

	if (!parsing(argc, argv, &game))
	{
		free_game_struct(&game);
		return (1);
	}
	if (!init_window(&mlx))
	{
		free_game_struct(&game);
		return (1);
	}
	game_loop(&game, &mlx);
	return (0);
}
