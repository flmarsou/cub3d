# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 10:49:02 by flmarsou          #+#    #+#              #
#    Updated: 2025/04/01 10:16:21 by flmarsou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE			:=	cub3d

# Files
VPATH		:=	src \
				src/utils \
				src/parser : src/parser/args : src/parser/keys : src/parser/colors : src/parser/map \
				src/game : src/game/init : src/game/render \

SRC			:=	main.c \
				free.c \

SRC_UTILS	:=	ft_isalnum.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_iskey.c \
				ft_ismap.c \
				ft_ispath.c \
				ft_strcmp.c \
				ft_strdup.c \
				ft_strlen.c \
				ft_strndup.c \
				get_next_line.c \

SRC_PARSER	:=	parsing.c \
				parse_args.c error_args.c \
				parse_keys.c store_keys.c error_keys.c \
				parse_colors.c store_colors.c error_colors.c \
				parse_map.c store_map.c check_map.c error_map.c \

SRC_MLX		:=	game_loop.c \
				init_window.c \
				init_image.c \
				init_texture.c \
				background.c \
				raycast_walls.c \
				raycast_doors.c \
				draw_walls.c \
				draw_doors.c \
				minimap.c \
				render.c \
				movement.c \
				keys.c \
				game_stop.c \

SOURCES		:= ${SRC} ${SRC_UTILS} ${SRC_PARSER} ${SRC_MLX}
OBJ_DIR		:= obj
OBJECTS		:=	${SOURCES:%.c=${OBJ_DIR}/%.o}

# Libraries
MINILIBX	:=	includes/.MiniLibX

# Variables
CC			:=	cc
CFLAGS		:=  -Wall -Wextra -Iincludes -Iincludes/.MiniLibX -O2
LIBXFLAGS	:=	-L${MINILIBX} -lmlx -lX11 -lXext -lm

# Makefile
all:			init_submodules | ${EXE}

init_submodules:
				@git submodule update --init --recursive > /dev/null

${EXE}:			${OBJECTS}
				@${MAKE} -C ${MINILIBX} > /dev/null 2>&1
				@${CC} ${CFLAGS} ${OBJECTS} ${LIBXFLAGS} -o ${EXE}

${OBJ_DIR}/%.o:	%.c | ${OBJ_DIR}
				@${CC} ${CFLAGS} -c $< -o $@

${OBJ_DIR}:
				@mkdir -p $@

clean:
				@${MAKE} -C ${MINILIBX} clean > /dev/null
				@rm -rf obj

fclean:			clean
				@rm -rf ${EXE}

re:				fclean all

.PHONY:			all clean fclean re
