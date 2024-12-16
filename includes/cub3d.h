/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:41:42 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/16 13:34:09 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>		// open
# include <unistd.h>	// close, read, write
# include <stdio.h>		// printf, perror
# include <stdlib.h>	// malloc, free
# include <string.h>	// strerror, exit
# include <stdbool.h>	// BooleansRenamed
# include "ansi.h"		// ANSI Defines

struct	s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	hex;
};

typedef struct s_cub
{
	char			*no_path;	// Path to north texture
	char			*so_path;	// Path to south texture
	char			*we_path;	// Path to west texture
	char			*ea_path;	// Path to east texture
	struct s_color	floor;		// Floor colors
	struct s_color	ceiling;	// Ceiling colors
	char			**map;		// 2D Array to store the map
}	t_cub;

//============================================================================//
//     Utils                                                                  //
//============================================================================//

void			ft_strerror(const char *str);

bool			ft_strcmp(char *str1, char *str2);

char			*ft_strdup(char *str);

unsigned int	ft_strlen(char *str);

//============================================================================//
//     Parser                                                                 //
//============================================================================//

bool			parsing(int argc, char **argv, t_cub *cub);
char			*get_next_line(int fd);

#endif
