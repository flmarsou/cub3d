/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:41:42 by flmarsou          #+#    #+#             */
/*   Updated: 2024/12/19 15:11:18 by flmarsou         ###   ########.fr       */
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

# define ERR	"\e[38;2;178;36;48m\e[1m[x] - Error: \e[38;2;255;255;255m"
# define WARN	"\e[38;2;186;79;155m\e[1m[!] - Warning: \e[38;2;255;255;255m"

# define NO		1
# define SO		2
# define WE		3
# define EA		4
# define F		5
# define C		6
# define NA_KEY	7

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
	bool			playing_found;
	char			facing;			// Starting facing direction
};

typedef struct s_game
{
	struct s_file	file;
}	t_game;

//============================================================================//
//     Source                                                                 //
//============================================================================//

void			free_file(t_game *game);

//============================================================================//
//     Utils                                                                  //
//============================================================================//

bool			ft_isalnum(char c);
bool			ft_isalpha(char c);
bool			ft_isdigit(char c);
bool			ft_iskey(char c);
bool			ft_ismap(char c);
bool			ft_ispath(char c);
bool			ft_strcmp(char *str1, char *str2);

char			*ft_strdup(char *str);
char			*ft_strndup(char *str, unsigned int len);
char			*get_next_line(int fd);

unsigned int	ft_strlen(char *str);

//============================================================================//
//     Parser                                                                 //
//============================================================================//

bool			parsing(int argc, char **argv, t_game *game);

//====================================//
//     Arguments                      //
//====================================//

/**
 * @brief Parses the command-line arguments for the program.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line argument strings.
 * @param fd Pointer to the file descriptor of the configuration file.
 * @return True if `args` are valid and the `fd` can be opened, false otherwise.
 */
bool			parse_args(int argc, char **argv, int *fd);

//====================================//
//     Keys                           //
//====================================//

/**
 * @brief Parses and validates keys from the input configuration file.
 * 
 * This function reads lines from the file, and parses them through all
 * the functions listed below.
 * @param fd Pointer to the file descriptor of the configuration file.
 * @param game Pointer to the main structure.
 * @return True if all keys are valid and registered, false otherwise.
 */
bool			parse_keys(int fd, t_game *game);

/**
 * @brief Checks if the given string matches a specific key format.
 * 
 * Supported keys are: "NO", "SO", "WE", "EA", "F", and "C".
 * @param line The string to be checked.
 * @return The corresponding key enum value, or 0 if no match is found.
 */
unsigned int	is_key(char *line);

/**
 * @brief Marks a key as found and ensures it is not duplicated.
 * 
 * @param key The key enum value.
 * @param game Pointer to the main structure.
 * @return True if the key was successfully marked as found, false otherwise.
 */
bool			found_key(unsigned int key, t_game *game);

/**
 * @brief Validates the formatting of a key and its associated value.
 * 
 * @param key The key enum value.
 * @param str The string to be checked.
 * @param len Pointer to store the length of the path from `str`.
 * @return True if the key is properly formatted, false otherwise.
 */
bool			check_key(unsigned int key, char *str, unsigned int *len);

/**
 * @brief Copies the path associated with a key in the game struct.
 * 
 * @param key The key enum value.
 * @param str The string to be checked.
 * @param len Length of the path from `str`.
 * @param game Pointer to the main structure.
 */
void			set_key(unsigned int key, char *str, unsigned int len,
					t_game *game);

/**
 * @brief Verifies if all required keys have been registered.
 * 
 * If `check` is true, missing keys result in an error.
 * @param game Pointer to the main structure.
 * @param check Whether to perform an error message on false.
 * @return True if all required keys are registered, false otherwise.
 */
bool			check_list(t_game *game, bool check);

//====================================//
//     Colors                         //
//====================================//

/**
 * @brief Parses and validates color information for the floor and ceiling keys.
 * 
 * This function ensures the floor and ceiling color strings are in the correct
 * RGB format. If valid, it calls `set_colors` to store the parsed values.
 * @param game Pointer to the main structure.
 * @return True if colors are valid, false otherwise.
 */
bool			parse_colors(t_game *game);

/**
 * @brief Validates if a string follows the RGB format for colors.
 * 
 * @param str The string to be checked.
 * @param key The key character ('F' or 'C') for error messages.
 * @return True if the format is valid, false otherwise.
 */
bool			check_colors(char *str, const char key);

/**
 * @brief Extracts and stores RGB color values for the floor and ceiling keys.
 * 
 * @param game Pointer to the main structure.
 */
void			set_colors(t_game *game);

//====================================//
//     Map                            //
//====================================//

bool			parse_map(int fd, t_game *game);

unsigned int	check_map_line(char *line, t_game *game);

void			set_map(t_game *game, char *line, unsigned int len);

#endif
