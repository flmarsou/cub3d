/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:52:48 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/20 14:27:04 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_file(t_game game)
{
	unsigned int	i;

	i = 0;
	printf("no_path: %s\n", game.file.no_path);
	printf("so_path: %s\n", game.file.so_path);
	printf("we_path: %s\n", game.file.we_path);
	printf("ea_path: %s\n", game.file.ea_path);
	printf("floor: %s\n", game.file.floor.raw);
	printf("r: %d\n", game.file.floor.r);
	printf("g: %d\n", game.file.floor.g);
	printf("b: %d\n", game.file.floor.b);
	printf("ceiling: %s\n", game.file.ceiling.raw);
	printf("r: %d\n", game.file.ceiling.r);
	printf("g: %d\n", game.file.ceiling.g);
	printf("b: %d\n", game.file.ceiling.b);
	if (game.file.map)
		while (game.file.map[i])
			printf("map[%u]: %s\n", i, game.file.map[i]);
	else
		printf("map: (null)\n");
	printf("facing: %d\n", game.file.facing);
}

static void	init_struct(t_game *game)
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

	init_struct(&game);
	if (!parsing(argc, argv, &game))
		return (1);
	free_file(&game);
	return (0);
}
