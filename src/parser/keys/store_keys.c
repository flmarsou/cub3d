/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:16:38 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/20 09:33:01 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	store_key(unsigned int key, char *str, unsigned int len, t_game *game)
{
	unsigned int	i;

	i = 0;
	while (ft_iskey(str[i]))
		i++;
	while (str[i] == ' ')
		i++;
	if (key == NO)
		game->file.no_path = ft_strndup(str + i, len);
	else if (key == SO)
		game->file.so_path = ft_strndup(str + i, len);
	else if (key == WE)
		game->file.we_path = ft_strndup(str + i, len);
	else if (key == EA)
		game->file.ea_path = ft_strndup(str + i, len);
	else if (key == F)
		game->file.floor.raw = ft_strndup(str + i, len);
	else if (key == C)
		game->file.ceiling.raw = ft_strndup(str + i, len);
}
