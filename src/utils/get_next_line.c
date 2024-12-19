/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:56:06 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/19 11:29:49 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define BUFFER_SIZE	256

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		line[256];
	static int	buffer_read = 0;
	static int	buffer_pos = 0;
	int			i;

	i = 0;
	while (true)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break ;
		}
		if (buffer[buffer_pos] == '\n')
		{
			buffer_pos++;
			break ;
		}
		if (i >= 255)
			return (NULL);
		line[i] = buffer[buffer_pos++];
		i++;
	}
	if (i == 0 && buffer_read <= 0)
		return (NULL);
	line[i] = '\0';
	return (ft_strdup(line));
}
