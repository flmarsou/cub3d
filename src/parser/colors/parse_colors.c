/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:56:52 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/20 09:38:19 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_digits(unsigned int digits, const char key,
	unsigned int values_found)
{
	const char		*arr[] = {"red", "green", "blue"};

	if (digits == 0)
		return (printf(ERR"%c key is missing %s!\n",
				key, arr[values_found]), false);
	if (digits > 3)
		return (printf(ERR"%c key %s is too large!\n",
				key, arr[values_found]), false);
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
			return (printf(ERR"%c key is mistyped!\n", key), false);
	}
	if (str[i] != '\0')
		return (printf(ERR"%c key is mistyped!\n", key), false);
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
