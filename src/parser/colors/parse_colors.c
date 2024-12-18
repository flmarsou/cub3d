/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:56:52 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/18 15:00:21 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_colors(t_game *game)
{
	if (!check_colors(game->file.floor.raw, 'F'))
		return (false);
	if (!check_colors(game->file.ceiling.raw, 'C'))
		return (false);
	set_colors(game);
	return (true);
}
