/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:01:58 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/17 14:23:52 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Checks if the given string is a key and returns its enum.
static unsigned int	is_key(char *str)
{
	unsigned int	i;

	i = 0;
	if (ft_iskey(str[i]) && str[i + 1] && str[i + 2])
	{
		if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
			return (NO);
		else if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
			return (SO);
		else if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
			return (WE);
		else if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
			return (EA);
		else if (str[i] == 'F' && str[i + 1] == ' ')
			return (F);
		else if (str[i] == 'C' && str[i + 1] == ' ')
			return (C);
	}
	return (0);
}

// Marks a key as true if it hasn't been registered yet. Ensures no duplicate.
static bool	found_key(unsigned int key, t_game *game)
{
	if (key == NO && game->file.check_list[0] == false)
		game->file.check_list[0] = true;
	else if (key == SO && game->file.check_list[1] == false)
		game->file.check_list[1] = true;
	else if (key == WE && game->file.check_list[2] == false)
		game->file.check_list[2] = true;
	else if (key == EA && game->file.check_list[3] == false)
		game->file.check_list[3] = true;
	else if (key == F && game->file.check_list[4] == false)
		game->file.check_list[4] = true;
	else if (key == C && game->file.check_list[5] == false)
		game->file.check_list[5] = true;
	else
	{
		printf("%u key already exists!\n", key);
		return (false);
	}
	return (true);
}

// Checks if a key is properly formatted with its corresponding value.
static bool	check_key(unsigned int key, char *str, unsigned int *len)
{
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
	{
		printf("%u key is mistyped!\n", key);
		return (false);
	}
	return (true);
}

// Checks if all required keys have been registered.
static bool	check_list(t_game *game)
{
	unsigned int	i;

	i = 0;
	while (i < 6)
	{
		if (game->file.check_list[i] == false)
			return (false);
		i++;
	}
	return (true);
}

bool	check_keys(int *fd, t_game *game)
{
	char			*line;
	unsigned int	key;
	unsigned int	len;

	line = get_next_line(*fd);
	while (line)
	{
		key = is_key(line);
		if (key > 0)
		{
			if (!found_key(key, game) || !check_key(key, line, &len))
				return (free(line), false);
			set_keys(key, line, len, game);
		}
		if (check_list(game) == true)
		{
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(*fd);
	}
	return (true);
}
