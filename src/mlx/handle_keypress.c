/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:11:00 by flmarsou          #+#    #+#             */
/*   Updated: 2025/02/17 10:23:42 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_game(game);
	if (key == KEY_W)
		puts("W key pressed!");
	else if (key == KEY_A)
		puts("A key pressed!");
	else if (key == KEY_S)
		puts("S key pressed!");
	else if (key == KEY_D)
		puts("D key pressed!");
	else if (key == KEY_ARROW_LEFT)
		puts("Arrow Left key pressed!");
	else if (key == KEY_ARROW_RIGHT)
		puts("Arrow Right key pressed!");
	return (0);
}
