/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:16:38 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/18 13:16:23 by flmarsou         ###   ########.fr       */
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
	if (key == FLAG_NO)
		game->no_path = ft_strndup(str + i, len);
	else if (key == FLAG_SO)
		game->so_path = ft_strndup(str + i, len);
	else if (key == FLAG_WE)
		game->we_path = ft_strndup(str + i, len);
	else if (key == FLAG_EA)
		game->ea_path = ft_strndup(str + i, len);
	else if (key == FLAG_F)
		game->floor_raw = ft_strndup(str + i, len);
	else if (key == FLAG_C)
		game->ceiling_raw = ft_strndup(str + i, len);
}
