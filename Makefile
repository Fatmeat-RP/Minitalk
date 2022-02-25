
SERVER_SRCS	=	${SRCSDIR}server.c

CLIENT_SRCS	=	${SRCSDIR}client.c

BUILDDIR	=	build/

CC		=	gcc

CLIENT		=	${BUILDDIR}client

SERVER		=	${BUILDDIR}server

FLAGS		=	-Wall -Werror -Wextra

HFLAGS	=	-Ifatlibc/include

all			: ${CLIENT} ${SERVER}

${CLIENT}	:	${CLIENT_SRCS}
			mkdir -p ${BUILDDIR}
			make -C fatlibc/
			$(CC) $(FLAGS) ${HFLAGS} ${CLIENT_SRCS} -o ${CLIENT} fatlibc/build/fatlibc.a

${SERVER}	:	${SERVER_SRCS}
			make -C fatlibc/
			$(CC) $(FLAGS) ${HFLAGS} ${SERVER_SRCS} -o ${SERVER} fatlibc/build/fatlibc.a

clean		:

fclean		:	clean
			rm -r ${BUILDDIR}

re			: