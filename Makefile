NAME	=	libftprintf.a

FLAGS	=	-Wall -Werror -Wextra

HEADER	=	ft_printf.h

SRCS	=	ft_printf.c ft_printf_utils.c ft_printf_utils2.c ft_printf_write.c

OBJS	=	${SRCS:%.c=%.o}

all:	${NAME}

${NAME}:	${OBJS} ${HEADER}
	ar rcs ${NAME} $?

%.o:	%.c ${HEADER}
	gcc ${FLAGS} -c $< -o $@

clean:
	rm -fr ${OBJS} ${OBJS_B}

fclean:	clean
	rm -fr ${NAME}

re:	fclean all

.PHONY:	all clean fclean re bonus
