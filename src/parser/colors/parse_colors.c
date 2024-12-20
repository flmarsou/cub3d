/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:56:52 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/20 15:06:44 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_digits(unsigned int digits, const char key,
	unsigned int values_found)
{
	if (digits == 0)
		return (error_colors(1, key, values_found));
	if (digits > 3)
		return (error_colors(2, key, values_found));
	return (true);
}

bool	check_format(char *str, const char key)
{
	unsigned int	values_found;
	unsigned int	i;
	unsigned int	digits;

	values_found = 0;
	i = 0;
	while (values_found < 3)
	{
		digits = 0;
		while (ft_isdigit(str[i]))
		{
			digits++;
			i++;
		}
		if (!check_digits(digits, key, values_found))
			return (false);
		values_found++;
		if (values_found < 3 && str[i++] != ',')
			return (error_colors(3, key, 0));
	}
	if (str[i] != '\0')
		return (error_colors(4, key, 0));
	return (true);
}

bool	parse_colors(t_game *game)
{
	if (!check_format(game->file.floor.raw, 'F'))
		return (false);
	if (!check_format(game->file.ceiling.raw, 'C'))
		return (false);
	store_colors(game);
	return (true);
}
