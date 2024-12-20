/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:45:52 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/20 14:34:28 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_args(int argc, char **argv, int *fd)
{
	if (argc < 2 || argv[1][0] == '\0')
		return (error_args(1));
	if (argc > 2)
		return (error_args(2));
	if (ft_strlen(argv[1]) < 5
		|| !ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub"))
		return (error_args(3));
	*fd = open(argv[1], __O_DIRECTORY);
	if (*fd != -1)
		return (error_args(4));
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
		return (error_args(5));
	return (true);
}
