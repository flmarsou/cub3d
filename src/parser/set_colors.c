/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:30:16 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/17 15:24:28 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Extracts the third component from the RGB raw string.
static unsigned char	get_blue(char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			blue[3];

	i = 0;
	j = 0;
	while (ft_isdigit(str[i]))
		i++;
	i++;
	while (ft_isdigit(str[i]))
		i++;
	i++;
	while (ft_isdigit(str[i]))
	{
		blue[j] = str[i];
		i++;
		j++;
	}
	blue[j] = '\0';
	return (ft_atouc(blue));
}

// Extracts the second component from the RGB raw string.
static unsigned char	get_green(char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			green[3];

	i = 0;
	j = 0;
	while (ft_isdigit(str[i]))
		i++;
	i++;
	while (ft_isdigit(str[i]))
	{
		green[j] = str[i];
		i++;
		j++;
	}
	green[j] = '\0';
	return (ft_atouc(green));
}

// Extracts the first component from the RGB raw string.
static unsigned char	get_red(char *str)
{
	unsigned int	i;
	char			red[3];

	i = 0;
	while (ft_isdigit(str[i]))
	{
		red[i] = str[i];
		i++;
	}
	red[i] = '\0';
	return (ft_atouc(red));
}

void	set_colors(t_game *game)
{
	game->file.floor.r = get_red(game->file.floor.raw);
	game->file.floor.g = get_green(game->file.floor.raw);
	game->file.floor.b = get_blue(game->file.floor.raw);
	game->file.ceiling.r = get_red(game->file.ceiling.raw);
	game->file.ceiling.g = get_green(game->file.ceiling.raw);
	game->file.ceiling.b = get_blue(game->file.ceiling.raw);
}
