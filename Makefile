all			: ${CLIENT} ${SERVER}

${CLIENT}	:	${CLIENT_OBJS}
			make -C lib/fatlibc/

${SERVER}	:	${SERVER_OBJS}
			make -C lib/fatlibc/

SERVER_OBJS	=	${SERVER_SRCS}

CLIENT_OBJS	=	${CLIENT_SRCS}

SERVER_SRCS	=	${SRCSDIR}server.c

CLIENT_SRCS	=	${SRCSDIR}client.c

BUILDDIR	=	build/

CLIENT		=	${BUILDDIR}client

SERVER		=	${BUILDDIR}server

clean		:
			rm -r ${SERVER_OBJS}
			rm -r ${CLIENT_OBJS}


fclean		:	clean
			rm -r ${BUILDDIR}

re			: