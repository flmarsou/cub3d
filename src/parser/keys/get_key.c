/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:38:43 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/18 14:03:02 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_key(char *line)
{
	unsigned int	i;

	i = 0;
	if (ft_iskey(line[i]) && line[i + 1] && line[i + 2])
	{
		if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
			return (NO);
		else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
			return (SO);
		else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
			return (WE);
		else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
			return (EA);
		else if (line[i] == 'F' && line[i + 1] == ' ')
			return (F);
		else if (line[i] == 'C' && line[i + 1] == ' ')
			return (C);
	}
	return (0);
}
