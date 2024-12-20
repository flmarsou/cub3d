/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:01:58 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/20 14:57:18 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_list(t_game *game, bool check)
{
	unsigned int	i;

	i = 0;
	while (i < 6)
	{
		if (check && !game->file.check_list[i])
			return (error_keys(4, 0, 0));
		if (!game->file.check_list[i])
			return (false);
		i++;
	}
	return (true);
}

bool	check_key(unsigned int key, char *str, unsigned int *len)
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
		return (error_keys(3, 0, key));
	return (true);
}

bool	found_key(unsigned int key, t_game *game)
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
	else if (key == NA_KEY)
		return (true);
	else
		return (error_keys(2, 0, key));
	return (true);
}

unsigned int	is_key(char *line)
{
	unsigned int	i;

	if (!line || *line == '\n' || *line == '\0')
		return (NA_KEY);
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

bool	parse_keys(int fd, t_game *game)
{
	char			*line;
	unsigned int	key;
	unsigned int	len;
	unsigned int	i;

	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		key = is_key(line);
		if (key == 0)
			return (free(line), error_keys(1, i, 0));
		if (!found_key(key, game) || !check_key(key, line, &len))
			return (free(line), false);
		store_key(key, line, len, game);
		if (check_list(game, false))
		{
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (check_list(game, true));
}
