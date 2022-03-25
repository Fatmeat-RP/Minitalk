# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 00:14:21 by acarle-m          #+#    #+#              #
#    Updated: 2022/03/25 18:53:18 by acarle-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	$(BUILDDIR)fatlibc.a

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

OBJSDIR		=	objs/

BUILDDIR	=	build/


FILE_OPS_SRCSDIR		=	lib_srcs/file_ops/

LIST_OPS_SRCSDIR		=	lib_srcs/list_ops/

LOGIC_OPS_SRCSDIR		=	lib_srcs/logic_ops/

MATH_OPS_SRCSDIR		=	lib_srcs/math_ops/

MEMORY_OPS_SRCSDIR		=	lib_srcs/memory_ops/

PRINT_OPS_SRCSDIR		=	lib_srcs/printf_ops/

STRING_OPS_SRCSDIR		=	lib_srcs/string_ops/


FILE_OPS_SRCS			=	$(FILE_OPS_SRCSDIR)ft_gnl.c

LIST_OPS_SRCS			=	$(LIST_OPS_SRCSDIR)ft_lstadd_back.c		\
							$(LIST_OPS_SRCSDIR)ft_lstadd_front.c	\
							$(LIST_OPS_SRCSDIR)ft_lstclear.c		\
							$(LIST_OPS_SRCSDIR)ft_lstdelone.c		\
							$(LIST_OPS_SRCSDIR)ft_lstiter.c			\
							$(LIST_OPS_SRCSDIR)ft_lstlast.c			\
							$(LIST_OPS_SRCSDIR)ft_lstmap.c			\
							$(LIST_OPS_SRCSDIR)ft_lstnew.c			\
							$(LIST_OPS_SRCSDIR)ft_lstsize.c

LOGIC_OPS_SRCS			=	$(wildcard $(LOGIC_OPS_SRCSDIR)*.c)	

MATH_OPS_SRCS			=	$(wildcard $(MATH_OPS_SRCSDIR)*.c)

MEMORY_OPS_SRCS			=	$(wildcard $(MEMORY_OPS_SRCSDIR)*.c)

PRINT_OPS_SRCS			=	$(wildcard $(PRINT_OPS_SRCSDIR)*.c)

STRING_OPS_SRCS			=	$(wildcard $(STRING_OPS_SRCSDIR)*.c)


FILE_OPS_OBJS			=	$(FILE_OPS_SRCS:$(FILE_OPS_SRCSDIR)%.c=$(OBJSDIR)%.o)

LIST_OPS_OBJS			=	$(LIST_OPS_SRCS:$(LIST_OPS_SRCSDIR)%.c=$(OBJSDIR)%.o)

LOGIC_OPS_OBJS			=	$(LOGIC_OPS_SRCS:$(LOGIC_OPS_SRCSDIR)%.c=$(OBJSDIR)%.o)

MATH_OPS_OBJS			=	$(MATH_OPS_SRCS:$(MATH_OPS_SRCSDIR)%.c=$(OBJSDIR)%.o)

MEMORY_OPS_OBJS			=	$(MEMORY_OPS_SRCS:$(MEMORY_OPS_SRCSDIR)%.c=$(OBJSDIR)%.o)

PRINT_OPS_OBJS			=	$(PRINT_OPS_SRCS:$(PRINT_OPS_SRCSDIR)%.c=$(OBJSDIR)%.o)

STRING_OPS_OBJS			=	$(STRING_OPS_SRCS:$(STRING_OPS_SRCSDIR)%.c=$(OBJSDIR)%.o)


HEADERS		=	include/ft_printf.h		\
				include/get_next_line.h	\
				include/libft.h

HFLAGS		=	-I include

all			:	$(NAME)

clean		:
				rm -rf $(OBJSDIR)

fclean		:	clean
				rm -rf $(BUILDDIR)

re			:	fclean all

$(NAME)		:	$(FILE_OPS_OBJS) $(LIST_OPS_OBJS) $(LOGIC_OPS_OBJS) $(MATH_OPS_OBJS) $(MEMORY_OPS_OBJS) $(PRINT_OPS_OBJS) $(STRING_OPS_OBJS)
				mkdir -p $(BUILDDIR)
				ar rcs $(NAME) $(FILE_OPS_OBJS) $(LIST_OPS_OBJS) $(LOGIC_OPS_OBJS) $(MATH_OPS_OBJS) $(MEMORY_OPS_OBJS) $(PRINT_OPS_OBJS) $(STRING_OPS_OBJS)

$(FILE_OPS_OBJS)	:	$(OBJSDIR)%.o :	$(FILE_OPS_SRCSDIR)%.c ${HEADERS}
						mkdir -p $(OBJSDIR)
						$(CC) $(FLAGS) ${HFLAGS} -c $< -o $@

$(LIST_OPS_OBJS)	:	$(OBJSDIR)%.o :	$(LIST_OPS_SRCSDIR)%.c ${HEADERS}
						mkdir -p $(OBJSDIR)
						$(CC) $(FLAGS) ${HFLAGS} -c $< -o $@

$(LOGIC_OPS_OBJS)	:	$(OBJSDIR)%.o :	$(LOGIC_OPS_SRCSDIR)%.c ${HEADERS}
						mkdir -p $(OBJSDIR)
						$(CC) $(FLAGS) ${HFLAGS} -c $< -o $@

$(MATH_OPS_OBJS)	:	$(OBJSDIR)%.o :	$(MATH_OPS_SRCSDIR)%.c ${HEADERS}
						mkdir -p $(OBJSDIR)
						$(CC) $(FLAGS) ${HFLAGS} -c $< -o $@

$(MEMORY_OPS_OBJS)	:	$(OBJSDIR)%.o :	$(MEMORY_OPS_SRCSDIR)%.c ${HEADERS}
						mkdir -p $(OBJSDIR)
						$(CC) $(FLAGS) ${HFLAGS} -c $< -o $@

$(PRINT_OPS_OBJS)	:	$(OBJSDIR)%.o :	$(PRINT_OPS_SRCSDIR)%.c ${HEADERS}
						mkdir -p $(OBJSDIR)
						$(CC) $(FLAGS) ${HFLAGS} -c $< -o $@

$(STRING_OPS_OBJS)	:	$(OBJSDIR)%.o :	$(STRING_OPS_SRCSDIR)%.c ${HEADERS}
						mkdir -p $(OBJSDIR)
						$(CC) $(FLAGS) ${HFLAGS} -c $< -o $@

.PHONY		:	all re clean fclean