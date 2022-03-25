# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 17:05:15 by acarle-m          #+#    #+#              #
#    Updated: 2022/02/28 17:05:15 by acarle-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SERVER_SRCS	=	${SRCSDIR}server.c

CLIENT_SRCS	=	${SRCSDIR}client.c

BUILDDIR	=	build/

CC		=	gcc

CLIENT		=	${BUILDDIR}client

SERVER		=	${BUILDDIR}server

FLAGS		=	-Wall -Werror -Wextra

HFLAGS	=	-Ifatlibc/include

all			: ${CLIENT} ${SERVER}

${CLIENT}	:	${CLIENT_SRCS} ./fatlibc/build/fatlibc.a
			mkdir -p ${BUILDDIR}
			make -C fatlibc/
			$(CC) $(FLAGS) ${HFLAGS} ${CLIENT_SRCS} -o ${CLIENT} fatlibc/build/fatlibc.a

${SERVER}	:	${SERVER_SRCS} ./fatlibc/build/fatlibc.a
			make -C fatlibc/
			$(CC) $(FLAGS) ${HFLAGS} ${SERVER_SRCS} -o ${SERVER} fatlibc/build/fatlibc.a

clean		:
			make clean -C fatlibc

fclean		:	clean
			make fclean -C fatlibc
			rm -r ${BUILDDIR}

re			:	fclean all