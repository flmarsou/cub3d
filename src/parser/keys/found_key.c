/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:27:47 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/18 13:28:56 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	found_key(unsigned int key, t_game *game)
{
	const char		*arr[] = {NULL, "NO", "SO", "WE", "EA", "F", "C"};

	if (key == NO && game->file.check_list[0] == false)
		game->file.check_list[0] = true;
	else if (key == SO && game->file.check_list[1] == false)
		game->file.check_list[1] = true;
	else if (key == WE && game->file.check_list[2] == false)
		game->file.check_list[2] = true;
	else if (key == EA && game->file.check_list[3] == false)
		game->file.check_list[3] = true;
	else if (key == F && game->file.check_list[4] == false)
		game->file.check_list[4] = true;
	else if (key == C && game->file.check_list[5] == false)
		game->file.check_list[5] = true;
	else
		return (printf(ERR"\"%s\" key already exists!\n", arr[key]), false);
	return (true);
}
