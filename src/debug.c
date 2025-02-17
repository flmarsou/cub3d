/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:37:45 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/17 08:38:06 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_file(t_game game)
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
