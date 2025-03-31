/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:46:41 by flmarsou          #+#    #+#             */
/*   Updated: 2025/03/31 14:47:35 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	error_keys(const unsigned int error, unsigned int line,
	const unsigned int key)
{
	const char		*arr[] = {NULL, "NO", "SO", "WE", "EA", "F", "C"};

	if (error == 1)
		printf(ERR"Unrecognized line %u!\n"RESET, line);
	else if (error == 2)
		printf(ERR"\"%s\" key already exists!\n"RESET, arr[key]);
	else if (error == 3)
		printf(ERR"\"%s\" key is mistyped!\n"RESET, arr[key]);
	return (false);
}
