/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:30:16 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/20 15:12:33 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned char	ft_atouc(char *str, const char key,
	const unsigned int color)
{
	const char		*arr[] = {"red", "green", "blue"};
	unsigned int	i;
	unsigned int	value;

	i = 0;
	value = 0;
	while (ft_isdigit(str[i]))
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	if (value > 255)
	{
		error_colors(5, key, color);
		return (255);
	}
	return (value);
}

// Extracts the third component from the RGB raw string.
static unsigned char	get_blue(char *str, const char key)
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
	return (ft_atouc(blue, key, 2));
}

// Extracts the second component from the RGB raw string.
static unsigned char	get_green(char *str, const char key)
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
	return (ft_atouc(green, key, 1));
}

// Extracts the first component from the RGB raw string.
static unsigned char	get_red(char *str, const char key)
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
	return (ft_atouc(red, key, 0));
}

void	store_colors(t_game *game)
{
	game->file.floor.r = get_red(game->file.floor.raw, 'F');
	game->file.floor.g = get_green(game->file.floor.raw, 'F');
	game->file.floor.b = get_blue(game->file.floor.raw, 'F');
	game->file.ceiling.r = get_red(game->file.ceiling.raw, 'C');
	game->file.ceiling.g = get_green(game->file.ceiling.raw, 'C');
	game->file.ceiling.b = get_blue(game->file.ceiling.raw, 'C');
}
