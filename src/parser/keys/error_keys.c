/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:46:41 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/20 15:14:07 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	error_keys(const unsigned int error, unsigned int line,
	const unsigned int key)
{
	const char		*arr[] = {NULL, "NO", "SO", "WE", "EA", "F", "C"};

	if (error == 1)
		printf(ERR"Unrecognized line %u!\n", line);
	else if (error == 2)
		printf(ERR"\"%s\" key already exists!\n", arr[key]);
	else if (error == 3)
		printf(ERR"\"%s\" key is mistyped!\n", arr[key]);
	return (false);
}
