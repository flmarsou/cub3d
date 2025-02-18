/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:41:42 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/18 13:19:18 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "ansi.h"			// ANSI Defines
# include "mlx.h"			// MiniLibX

# include <fcntl.h>			// open
# include <unistd.h>		// close, read, write
# include <stdio.h>			// printf, perror
# include <stdlib.h>		// malloc, free
# include <string.h>		// strerror, exit
# include <stdbool.h>		// Booleans
# include <math.h>

//============================================================================//
//     Defines                                                                //
//============================================================================//

// Debug
# define ERR	"\e[38;2;178;36;48m\e[1m[x] - Error: \e[38;2;255;255;255m"
# define WARN	"\e[38;2;186;79;155m\e[1m[!] - Warning: \e[38;2;255;255;255m"
# define OK		"\e[38;2;25;159;54m\e[1m[o] - Success: \e[38;2;255;255;255m"

// Keys
enum
{
	FLAG_NO		= (1 << 0),
	FLAG_SO		= (1 << 1),
	FLAG_WE		= (1 << 2),
	FLAG_EA		= (1 << 3),
	FLAG_F		= (1 << 4),
	FLAG_C		= (1 << 5),
	FLAG_ACCEPT	= (FLAG_NO | FLAG_SO | FLAG_WE | FLAG_EA | FLAG_F | FLAG_C)
};

// Map Characters
# define N		'N'
# define S		'S'
# define W		'W'
# define E		'E'
# define EMPTY	' '
# define WALL	'1'
# define GROUND	'0'

// MiniLibX - Window
# define WIN_X				1280
# define WIN_Y				720
# define WIN_TITLE			"Cub3D - By flmarsou and rdedola"

// MiniLibX - Events
# define KEY_PRESS			2
# define DESTROY_NOTIFY		17

// MiniLibX - Masks
# define NO_EVENT_MASK		0L
# define KEY_PRESS_MASK		1L

// MiniLibX - Keys
# define KEY_ESC			65307
# define KEY_ARROW_LEFT		65361
# define KEY_ARROW_RIGHT	65363
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

//============================================================================//
//     Structs                                                                //
//============================================================================//

//====================================//
//     Parsing                        //
//====================================//

typedef struct s_game
{
	// Keys
	char			*no_path;			// Path to north texture (NO)
	char			*so_path;			// Path to south texture (SO)
	char			*we_path;			// Path to west texture (WE)
	char			*ea_path;			// Path to east texture (EA)
	char			*floor_raw;			// Color String (F)
	char			*ceiling_raw;		// Color String (C)
	char			**map;				// 2D Array to store the map
	unsigned int	floor_hex;			// Color Hex (F)
	unsigned int	ceiling_hex;		// Color Hex (C)
	unsigned char	bit_flag;			// Key Registry
	// Map
	bool			player_found : 1;
	char			facing : 7;			// Starting facing direction
	unsigned int	height;				// Map Height
	// Raycasting
	double			pos_x;				// Player X position
	double			pos_y;				// Player Y position
}	t_game;

//====================================//
//     MiniLibX                       //
//====================================//

struct s_bg
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
};

typedef struct s_mlx
{
	// MiniLibX
	void			*mlx;			// MiniLibX pointer
	void			*win;			// Window pointer
	// Images
	struct s_bg		bg;
}	t_mlx;

typedef struct s_main
{
	t_game			*game;
	t_mlx			*mlx;
}	t_main;

//============================================================================//
//     Source                                                                 //
//============================================================================//

// Free
void			free_game_struct(t_game *game);

// Debug
void			print_file(t_game game);

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

/**
 * 1: "Not enough arguments!"
 * 2: "Too many arguments!"
 * 3: "Wrong arguments!"
 * 4: "File is a directory!"
 * 5: "File not found!"
 */
bool			error_args(const unsigned int error);

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
void			store_key(unsigned int key, char *str, unsigned int len,
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

/**
 * 1: "Unrecognized line `line`"
 * 2: "`key_enum` key already exists!"
 * 3: "`key_enum` key is mistyped"
 * 4: "Missing key(s)!""
 */
bool			error_keys(const unsigned int error, unsigned int line,
					const unsigned int key);

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
bool			check_format(char *str, const char key);

/**
 * @brief Extracts and stores RGB color values for the floor and ceiling keys.
 * 
 * @param game Pointer to the main structure.
 */
void			store_colors(t_game *game);

/**
 * 1: "`key_char` key is missing `color`!"
 * 2: "`color` is too large in `key_char` key!"
 * 3: "`key_char` key is mistyped!"
 * 4: "Unrecognized character(s) after `key_char` key!"
 * 5: "In `key_char` key `color` value has been set to max."
 */
bool			error_colors(const unsigned int error, const char key,
					unsigned int color);

//====================================//
//     Map                            //
//====================================//

/**
 * @brief Parses and validates keys from the input configuration file.
 * 
 * @param fd Pointer to the file descriptor of the configuration file.
 * @param game Pointer to the main structure.
 * @return True if the map is valid, false otherwise.
 */
bool			parse_map(int fd, t_game *game);

/**
 * @brief Reads lines from the file after the keys.
 * 
 * @param fd Pointer to the file descriptor of the configuration file.
 * @param game Pointer to the main structure.
 * @return True if the map is valid, false otherwise.
 */
bool			read_map(int fd, t_game *game);

/**
 * @brief Checks if the given string only have map characters.
 * 
 * Supported keys are: '0', '1', ' ', ('N', 'S', 'W', 'E' only once).
 * @param game Pointer to the main structure.
 * @param line The string to be checked.
 * @return 2 if empty or 0 if correct, 1 otherwise.
 */
unsigned int	check_map_line(t_game *game, char *line);

/**
 * @brief Copies the address of the line in the game struct.
 * 
 * @param game Pointer to the main structure.
 * @param line The string to be checked.
 * @param line_index Iteration of line from the map.
 */
void			store_map(t_game *game, char *line, unsigned int line_index);

/**
 * @brief Stores the player's (X, Y) position, and its facing direction.
 * 
 * @param game Pointer to the main structure.
 * @param line The string to be checked.
 * @param line_index Iteration of line from the map.
 */
void			store_player_info(t_game *game, char *line,
					unsigned int line_index);

/**
 * @brief Validates the game map to ensure it meets the required constraints.
 * 
 * 1. The top and bottom rows consist only of '1' or ' ' characters.
 * 2. The leftmost and rightmost characters of each row are '1' or ' '.
 * 3. All '0' are fully enclosed by '1', with no adjacent ' '.
 * @param game Pointer to the main structure.
 */
bool			check_map(t_game *game);

/**
 * 1: "Unrecognized character in map `char`!"
 * 2: "Multiple players found in the map!"
 * 3: "No player found in the map!"
 * 4: "Map is opened X: `x` Y: `y`"
 */
bool			error_map(const unsigned int error, const char c,
					const unsigned int x, const unsigned int y);

//============================================================================//
//     MiniLibX                                                               //
//============================================================================//

//====================================//
//     Init                           //
//====================================//

/**
 * @brief Initializes a sized window with a title and opens it.
 * 
 * @param mlx Pointer to the mlx structure.
 */
bool			init_window(t_mlx *mlx);

/**
 * @brief Creates the background image.
 * 
 * This function manually creates and stores a background image for later uses.
 * Its size is `WIN_X` x `WIN_Y`, with the upper and lower halves colored
 * according to `floor_hex (F Key)` and `ceiling_hex (C Key)`.
 * 
 * @param mlx Pointer to the mlx structure.
 */
void			init_background(t_game game, t_mlx *mlx);

//====================================//
//     Game Loop                      //
//====================================//

void			game_loop(t_game *game, t_mlx *mlx);

int				close_game(t_game *game, t_mlx *mlx);

#endif
