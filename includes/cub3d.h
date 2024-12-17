/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:41:42 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/17 14:54:45 by flmarsou         ###   ########.fr       */
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

# define NO	1
# define SO	2
# define WE	3
# define EA	4
# define F	5
# define C	6

struct	s_color
{
	char			*raw;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
};

struct s_file
{
	char			*no_path;		// Path to north texture
	char			*so_path;		// Path to south texture
	char			*we_path;		// Path to west texture
	char			*ea_path;		// Path to east texture
	struct s_color	floor;			// Floor colors
	struct s_color	ceiling;		// Ceiling colors
	bool			check_list[6];
	char			**map;			// 2D Array to store the map
	char			facing;			// Starting facing direction
};

typedef struct s_game
{
	struct s_file	file;
}	t_game;

//============================================================================//
//     Utils                                                                  //
//============================================================================//

void			ft_strerror(const char *str);

bool			ft_isalnum(char c);
bool			ft_isalpha(char c);
bool			ft_isdigit(char c);
bool			ft_iskey(char c);
bool			ft_ispath(char c);
bool			ft_strcmp(char *str1, char *str2);

char			*ft_strdup(char *str);
char			*ft_strndup(char *str, unsigned int len);
char			*get_next_line(int fd);

unsigned char	ft_atouc(char *str);

unsigned int	ft_strlen(char *str);

//============================================================================//
//     Parser                                                                 //
//============================================================================//

bool			parsing(int argc, char **argv, t_game *game);

bool			check_args(int argc, char **argv, int *fd);
bool			check_keys(int *fd, t_game *game);
bool			check_colors(t_game *game);

void			set_keys(unsigned int key, char *str, unsigned int len,
					t_game *game);
void			set_colors(t_game *game);

#endif
