NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_putnbr.c ft_printf_hex.c ft_printf_str.c ft_printf_ptr.c

OBJS = ${SRCS:.c=.o}
LIBC = ar rc
RM = rm -f

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o  ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 

re: fclean all

.PHONY : clean