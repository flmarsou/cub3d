/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:58:08 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/20 15:14:15 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	error_colors(const unsigned int error, const char key,
	unsigned int color)
{
	const char	*arr[] = {RED1"Red"RESET, GREEN3"Green"RESET, BLUE2"Blue"RESET};

	if (error == 1)
		printf(ERR"%c key is missing %s!\n", key, arr[color]);
	else if (error == 2)
		printf(ERR"%s is too large in %c key!\n", arr[color], key);
	else if (error == 3)
		printf(ERR"%c key is mistyped!\n", key);
	else if (error == 4)
		printf(ERR"Unrecognized character(s) after %c key!\n", key);
	else if (error == 5)
		printf(WARN"In %c key %s value has been set to max.\n",
			key, arr[color]);
	return (false);
}
