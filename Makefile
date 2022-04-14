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

LIBS = fatlibc/build/fatlibc.a

all			: $(LIBS) directory ${CLIENT} ${SERVER}

${CLIENT}	:	${CLIENT_SRCS} ${LIBS}
			
			@$(CC) $(FLAGS) ${HFLAGS} ${CLIENT_SRCS} -o ${CLIENT} ${LIBS}

${SERVER}	:	${SERVER_SRCS} ${LIBS}
			@$(CC) $(FLAGS) ${HFLAGS} ${SERVER_SRCS} -o ${SERVER} ${LIBS}

${LIBS}		:
			@make -C fatlibc/

directory	:
			@mkdir -p ${BUILDDIR}

clean		:
			@make clean -C fatlibc

fclean		:	clean
			@make fclean -C fatlibc
			@rm -rf ${BUILDDIR}

re			:	fclean all
