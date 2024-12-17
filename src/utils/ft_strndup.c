/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:40:56 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/17 11:48:25 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strndup(char *str, unsigned int len)
{
	char			*dup;
	unsigned int	i;

	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] && i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
