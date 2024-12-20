/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:15:23 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/20 15:58:33 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	error_map(const unsigned int error, const char c, const unsigned int x,
	const unsigned int y)
{
	if (error == 1)
		printf(ERR"Unrecognized character in map '%c'!\n", c);
	else if (error == 2)
		printf(ERR"Multiple players found in the map!\n");
	else if (error == 3)
		printf(ERR"No player found in the map!\n");
	else if (error == 4)
		printf(ERR"Map is opened X: %u Y: %u\n", x, y);
	return (false);
}
