/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:01:58 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/18 13:16:12 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_list(t_game *game, bool check)
{
	unsigned int	i;

	i = 0;
	while (i < 6)
	{
		if (check && game->bit_flag != FLAG_ACCEPT)
			return (error_keys(4, 0, 0));
		if (game->bit_flag != FLAG_ACCEPT)
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
	if (key == FLAG_NO && !(game->bit_flag & FLAG_NO))
		game->bit_flag |= FLAG_NO;
	else if (key == FLAG_SO && !(game->bit_flag & FLAG_SO))
		game->bit_flag |= FLAG_SO;
	else if (key == FLAG_WE && !(game->bit_flag & FLAG_WE))
		game->bit_flag |= FLAG_WE;
	else if (key == FLAG_EA && !(game->bit_flag & FLAG_EA))
		game->bit_flag |= FLAG_EA;
	else if (key == FLAG_F && !(game->bit_flag & FLAG_F))
		game->bit_flag |= FLAG_F;
	else if (key == FLAG_C && !(game->bit_flag & FLAG_C))
		game->bit_flag |= FLAG_C;
	else if (key == 42)
		return (true);
	else
		return (error_keys(2, 0, key));
	return (true);
}

unsigned int	is_key(char *line)
{
	unsigned int	i;

	if (!line || *line == '\n' || *line == '\0')
		return (42);
	i = 0;
	if (ft_iskey(line[i]) && line[i + 1] && line[i + 2])
	{
		if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
			return (FLAG_NO);
		else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
			return (FLAG_SO);
		else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
			return (FLAG_WE);
		else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
			return (FLAG_EA);
		else if (line[i] == 'F' && line[i + 1] == ' ')
			return (FLAG_F);
		else if (line[i] == 'C' && line[i + 1] == ' ')
			return (FLAG_C);
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
