/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:56:52 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/17 15:25:53 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Checks if a RGB string is properly formatted: "XXX,XXX,XXX".
static bool	is_rgb_format(char *str)
{
	unsigned int	values_found;
	unsigned int	i;
	unsigned int	digits;

	values_found = 0;
	i = 0;
	while (values_found < 3)
	{
		digits = 0;
		while (ft_isdigit(str[i++]))
			digits++;
		if (digits == 0 || digits > 3)
			return (false);
		values_found++;
		if (values_found < 3 && str[i - 1] != ',')
			return (false);
	}
	if (str[i] != '\0')
		return (false);
	return (true);
}

bool	check_colors(t_game *game)
{
	if (!is_rgb_format(game->file.floor.raw)
		&& !is_rgb_format(game->file.ceiling.raw))
		return (false);
	if (ft_strlen(game->file.floor.raw) > 11)
		return (false);
	if (ft_strlen(game->file.ceiling.raw) > 11)
		return (false);
	set_colors(game);
	return (true);
}
