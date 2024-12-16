# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 10:49:02 by flmarsou          #+#    #+#              #
#    Updated: 2024/12/16 13:24:39 by flmarsou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE			:=	cub3d

# Files
VPATH		:=	src:src/utils:src/parser

SRC			:=	main.c \

SRC_UTILS	:=	ft_strcmp.c \
				ft_strdup.c \
				ft_strerror.c \
				ft_strlen.c \

SRC_PARSER	:=	parsing.c \

SOURCES		:= ${SRC} ${SRC_UTILS} ${SRC_PARSER}
OBJ_DIR		:= obj
OBJECTS		:=	${SOURCES:%.c=${OBJ_DIR}/%.o}

# Variables
CC			:=	cc
CFLAGS		:=  -Iincludes -O2

# Makefile
all:		${EXE}

${EXE}:		${OBJECTS}
			@${CC} ${CFLAGS} $^ -o $@

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
