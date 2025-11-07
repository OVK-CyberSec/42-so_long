LIB = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./

LIBC =	ft_split.c ft_strncmp.c \
		ft_strdup.c ft_strlcpy.c ft_strlen.c \
		ft_strnstr.c gnl.c ft_strncpy.c ft_strjoin.c \
		ft_printf/ft_print_ptr.c ft_printf/ft_printf.c \
		ft_printf/ft_putchar_fd.c ft_printf/print_format.c \
		ft_printf/print_utils.c \

SRCS = ${LIBC}

SRCSALL = ${LIBC}

OBJS = ${SRCS:.c=.o}

OBJSALL = ${SRCSALL:.c=.o} 

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIB}:	${OBJS}
		ar -rsc ${LIB} ${OBJS}

bonus:	${OBJSALL}
		ar -rsc ${LIB} ${OBJSALL}

all: 	${LIB}

clean:	
		rm -f ${OBJSALL}

fclean:	clean;
		rm -f ${LIB}

re:	fclean all

.PHONY: all clean fclean re bonus