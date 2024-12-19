/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:55:18 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/19 10:03:01 by flmarsou         ###   ########.fr       */
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

bool	check_colors(char *str, const char key)
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
