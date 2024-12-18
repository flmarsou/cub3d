/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:55:18 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/18 14:55:51 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_colors(char *str, const char key)
{
	const char		*arr[] = {"red", "green", "blue"};
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
		if (digits == 0)
			return (printf(ERR"%c key is missing %s!\n",
					key, arr[values_found]), false);
		if (digits > 3)
			return (printf(ERR"%c key %s is too large!\n",
					key, arr[values_found]), false);
		values_found++;
		if (values_found < 3 && str[i - 1] != ',')
			return (printf(ERR"%c key is mistyped!\n", key), false);
	}
	if (str[i] != '\0')
		return (printf(ERR"%c key is mistyped!\n", key), false);
	return (true);
}
