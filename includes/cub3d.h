/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:41:42 by flmarsou          #+#    #+#             */
/*   Updated: 2025/04/01 10:16:01 by flmarsou         ###   ########.fr       */
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

// MiniLibX - Window
# define WIN_X					1280
# define WIN_Y					720
# define WIN_TITLE				"Cub3D - By flmarsou and rdedola"

// MiniLibX - Events
# define KEY_PRESS				2
# define KEY_RELEASE			3
# define MOTION_NOTIFY			6
# define DESTROY_NOTIFY			17

// MiniLibX - Masks
# define NO_EVENT_MASK			0L
# define KEY_PRESS_MASK			1L
# define KEY_RELEASE_MASK		2L
# define POINTER_MOTION_MASK	64L

// MiniLibX - Keys
# define KEY_ESC				65307
# define KEY_ARROW_LEFT			65361
# define KEY_ARROW_RIGHT		65363
# define KEY_E					101
# define KEY_W					119
# define KEY_A					97
# define KEY_S					115
# define KEY_D					100
# define KEY_LEFT_SHIFT			65505
# define KEY_M					109
# define KEY_LEFT_CTRL			65507

// Player Options
# define MOVE_SPEED				0.01f
# define ROT_SPEED				0.006f
# define CROUCH_MULTIPLIER		0.33f
# define RUN_MULTIPLIER			1.66f
// Minimap Options
# define CELL_COUNT				21			// X and Y cells count
# define CELL_SIZE				10			// X and Y pixel count per cell
# define CELL_GROUND_COLOR		0xFFFFFF
# define CELL_WALL_COLOR		0x808080
# define CELL_DOOR_COLOR		0xFF0000
# define CELL_EMPTY_COLOR		0x000000

// Door Textures
# define DOOR_1					"./assets/textures/doors/1.xpm"
# define DOOR_2					"./assets/textures/doors/2.xpm"
# define DOOR_3					"./assets/textures/doors/3.xpm"
# define DOOR_4					"./assets/textures/doors/4.xpm"

//============================================================================//
//     Structs                                                                //
//============================================================================//

//====================================//
//     Parsing                        //
//====================================//

typedef struct s_game
{
	// Map & Parsing
	char			*no_path;			// Path to north texture (NO)
	char			*so_path;			// Path to south texture (SO)
	char			*we_path;			// Path to west texture (WE)
	char			*ea_path;			// Path to east texture (EA)
	char			*d_path;			// Path to door texture
	char			*floor_raw;			// Color String (F)
	char			*ceiling_raw;		// Color String (C)
	char			**map;				// 2D Array to store the map
	unsigned int	floor_hex;			// Color Hex (F)
	unsigned int	ceiling_hex;		// Color Hex (C)
	unsigned char	bit_flag;			// Key Registry
	bool			player_found;		// Flag bool for player detection
	char			facing;				// Starting facing direction
	unsigned int	height;				// Map Height
	bool			has_doors;			// Checks if map has doors
	// Raycasting
	float			pos_x;				// Player X position
	float			pos_y;				// Player Y position
	int				map_x;				// Player X grid cell
	int				map_y;				// Player Y grid cell
	float			dir_x;				// Camera X direction
	float			dir_y;				// Camera Y direction
	float			plane_x;			// Camera X plane
	float			plane_y;			// Camera Y plane
	float			camera_x;			// Camera X position
	float			ray_dir_x;			// X direction of the ray
	float			ray_dir_y;			// Y direction of the ray
	float			delta_dist_x;		// Distance the ray moves in X direction
	float			delta_dist_y;		// Distance the ray moves in Y direction
	float			side_dist_x;		// Distance to the next X grid line
	float			side_dist_y;		// Distance to the next Y grid line
	int				step_x;				// Value for moving in the X direction
	int				step_y;				// Value for moving in the Y direction
	int				side;				// X or Y ray hit
	int				line_height;		// Wall line height
	float			perp_wall_dist;		// Player-Wall perpendicular distance
	bool			doors_interact;		// E to open/close doors
	// Texturing
	int				texture;			// NO, SO, WE, EA ray hit
	int				texture_x;
	int				texture_y;
	float			texture_pos;
	float			step;
	int				draw_start;			// Top of the wall
	int				draw_end;			// Bottom of the wall
	// Other
	float			speed_multiplier;	// Running and diagonal speed
	int				scan_y;				// Minimap Y
	int				scan_x;				// Minimap X
}	t_game;

//====================================//
//     MiniLibX                       //
//====================================//

struct s_texture
{
	void				*img;
	int					*data;
	int					width;
	int					height;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
};

struct s_image
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
};

typedef struct s_mlx
{
	void				*mlx;
	void				*win;
	struct s_image		image;
	struct s_texture	texture[8];
	bool				key_pressed[9];
	unsigned int		frames;
}	t_mlx;

// Struct for passing both t_game and t_mlx
typedef struct s_data
{
	t_game			*game;
	t_mlx			*mlx;
}	t_data;

//============================================================================//
//     Source                                                                 //
//============================================================================//

// Free
void			free_game_struct(t_game *game);

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
 * @brief Initializes the image buffer.
 * 
 * This function creates an `WIN_X` x `WIN_Y` sized image buffer for later uses.
 * 
 * @param mlx Pointer to the mlx structure.
 */
void			init_image(t_mlx *mlx);

/**
 * @brief Initializes the xpm files textures.
 * 
 * This function creates pointers to the XPM files for later uses.
 * 
 * @param mlx Pointer to the mlx structure.
 */
bool			init_texture(t_game game, t_mlx *mlx);

//====================================//
//     Game Loop                      //
//====================================//

/**
 * @brief Loop function for the MiniLibX.
 * 
 * Runs all initialization functions for the image buffer, textures, etc...
 * Reads user input (key press, key release, etc...).
 * Runs the MiniLibX loop for rendering and movements.
 * 
 * @param game Pointer to the main structure.
 * @param mlx Pointer to the mlx structure.
 * @return The newer speed of the player in the game.
 */
void			game_loop(t_game *game, t_mlx *mlx);

/**
 * @brief Add a background to the image buffer.
 * 
 * Draws the `C` key color from the .cub file on the upper half,
 * and the `F` key color on the lower half.
 * 
 * @param game Pointer to the main structure.
 * @param mlx Pointer to the mlx structure.
 * @return The newer speed of the player in the game.
 */
void			background(t_game game, t_mlx *mlx);

/**
 * @brief Add a minimap to the image buffer.
 * 
 * @param game Pointer to the main structure.
 * @param mlx Pointer to the mlx structure.
 * @return The newer speed of the player in the game.
 */
void			minimap(t_game game, t_mlx *mlx);

/**
 * @brief Does all the necessary calculations for raycasting.
 * 
 * 1. Calculates the distance from the player and the walls.
 * 2. perform_dda
 * 3. Calculates the walls distance and height.
 * 
 * @param game Pointer to the main structure.
 * @param mlx Pointer to the mlx structure.
 */
void			raycast_walls(t_game *game, t_mlx *mlx);
void			raycast_doors(t_game *game, t_mlx *mlx, unsigned char frame);

// TODO: Comments
void			draw_walls(t_game *game, t_mlx *mlx, unsigned int x);
void			draw_doors(t_game *game, t_mlx *mlx, unsigned int x,
					unsigned char frame);

// TODO: Comments
void			render(t_game *game, t_mlx *mlx);

// TODO: Comments
int				handle_keypress(int key, t_data *data);
int				handle_keyrelease(int key, t_data *data);

/**
 * @brief Calculates the player's movement speed based on game settings.
 * 
 * This function returns the speed at which the player can move,
 * taking into account various game factors like diagonal inputs,
 * running, and crouching.
 * 
 * @param game Pointer to the main structure.
 * @param mlx Pointer to the mlx structure.
 * @return The newer speed of the player in the game.
 */
float			get_speed(t_game *game, t_mlx *mlx);

/**
 * @brief Rotates the player's camera based on input.
 * 
 * This function handles the player's camera angle based on user input,
 * allowing the player to look left or right.
 * 
 * @param game Pointer to the main structure.
 * @param speed The speed at which to rotate the camera.
 */
void			rotate(t_game *game, float speed);

/**
 * @brief Moves the player forward or backward based on input.
 * 
 * This function handles movement, allowing the player 
 * to move forward or backward.
 * 
 * @param game Pointer to the main structure.
 * @param key The key press that indicates the strafing direction.
 * @param speed The speed at which to move.
 */
void			move(t_game *game, int key, float speed);

/**
 * @brief Strafes the player left or right based on input.
 * 
 * This function handles strafing (sideways movement), allowing the player 
 * to move left or right.
 * 
 * @param game Pointer to the main structure.
 * @param key The key press that indicates the strafing direction.
 * @param speed The speed at which to strafe.
 */
void			strafe(t_game *game, int key, float speed);

/**
 * @brief Closes the game and frees allocated resources.
 * 
 * This function handles cleaning up any resources and properly exits the game,
 * closing the window and releasing any used resources.
 * 
 * @param data Pointer to the data structure containing game and mlx.
 */
int				close_game(t_data *data);

#endif
