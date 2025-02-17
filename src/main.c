/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:52:48 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/17 15:29:24 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_game_struct(t_game *game)
{
	unsigned int	i;

	i = 0;
	while (i < 6)
		game->file.check_list[i++] = false;
	game->file.map = NULL;
	game->file.player_found = false;
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
	init_background(&game);
	game_loop(&game);
	return (0);
}
