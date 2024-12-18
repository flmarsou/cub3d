/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:05:54 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/18 14:07:52 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_key(unsigned int key, char *str, unsigned int *len)
{
	const char		*arr[] = {NULL, "NO", "SO", "WE", "EA", "F", "C"};
	unsigned int	i;

	i = 0;
	*len = 0;
	while (ft_iskey(str[i]))
		i++;
	while (str[i] == ' ')
		i++;
	while (ft_ispath(str[i]))
	{
		(*len)++;
		i++;
	}
	if (str[i] != '\0')
		return (printf(ERR"\"%s\" key is mistyped!\n", arr[key]), false);
	return (true);
}
