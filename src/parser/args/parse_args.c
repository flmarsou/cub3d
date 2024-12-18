/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:45:52 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/18 14:01:15 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_args(int argc, char **argv, int *fd)
{
	if (argc < 2 || argv[1][0] == '\0')
		return (printf(ERR"Not enough arguments!\n"), false);
	if (argc > 2)
		return (printf(ERR"Too many arguments!\n"), false);
	if (ft_strlen(argv[1]) < 5
		|| !ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub"))
		return (printf(ERR"Wrong arguments!\n"), false);
	*fd = open(argv[1], __O_DIRECTORY);
	if (*fd != -1)
	{
		close (*fd);
		return (printf(ERR"File is a directory!\n"), false);
	}
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
	{
		close(*fd);
		return (printf(ERR"File not found!\n"), false);
	}
	return (true);
}
