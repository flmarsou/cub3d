/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:45:52 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/17 08:46:00 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_args(int argc, char **argv, int *fd)
{
	if (argc < 2 || argv[1][0] == '\0')
		return (ft_strerror("Not enough arguments!"), false);
	if (argc > 2)
		return (ft_strerror("Too many arguments!"), false);
	if (ft_strlen(argv[1]) < 5
		|| !ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub"))
		return (ft_strerror("Wrong arguments!"), false);
	*fd = open(argv[1], __O_DIRECTORY);
	if (*fd != -1)
	{
		close (*fd);
		return (ft_strerror("File is a directory!"), false);
	}
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
	{
		close(*fd);
		return (ft_strerror("File not found!"), false);
	}
	return (true);
}
