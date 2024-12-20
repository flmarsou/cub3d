/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:34:17 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/20 14:34:30 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	error_args(const unsigned int error)
{
	if (error == 1)
		printf(ERR"Not enough arguments!\n");
	else if (error == 2)
		printf(ERR"Too many arguments!\n");
	else if (error == 3)
		printf(ERR"Wrong arguments!\n");
	else if (error == 4)
		printf(ERR"File is a directory!\n");
	else if (error == 5)
		printf(ERR"File not found!\n");
	return (false);
}
