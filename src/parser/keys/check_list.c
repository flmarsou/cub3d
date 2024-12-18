/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:11:41 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/18 14:12:11 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_list(t_game *game, bool check)
{
	unsigned int	i;

	i = 0;
	while (i < 6)
	{
		if (check && !game->file.check_list[i])
			return (printf(ERR"Missing key(s)!\n"), false);
		if (!game->file.check_list[i])
			return (false);
		i++;
	}
	return (true);
}
