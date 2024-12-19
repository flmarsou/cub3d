# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 10:49:02 by flmarsou          #+#    #+#              #
#    Updated: 2024/12/19 15:29:59 by flmarsou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE			:=	cub3d

# Files
VPATH		:=	src : \
				src/utils : \
				src/parser : src/parser/args : src/parser/keys : src/parser/colors : src/parser/map \

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
				parse_args.c \
				parse_keys.c is_key.c found_key.c check_key.c set_key.c check_list.c \
				parse_colors.c check_colors.c set_colors.c \
				parse_map.c check_map_line.c set_map.c \

SOURCES		:= ${SRC} ${SRC_UTILS} ${SRC_PARSER}
OBJ_DIR		:= obj
OBJECTS		:=	${SOURCES:%.c=${OBJ_DIR}/%.o}

# Variables
CC			:=	cc
CFLAGS		:=  -Iincludes -O2 -flto

# Makefile
all:		${EXE}

${EXE}:		${OBJECTS}
			@${CC} -Wl,-s ${CFLAGS} $^ -o $@

${OBJ_DIR}/%.o:	%.c | ${OBJ_DIR}
			@${CC} ${CFLAGS} -c $< -o $@

${OBJ_DIR}:
			@mkdir -p $@

clean:
			@rm -rf obj

fclean:		clean
			@rm -rf ${EXE}

re:			fclean all

.PHONY:		all clean fclean re
