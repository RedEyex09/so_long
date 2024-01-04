NAME = so_long.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./ft_printf/ft_printf.c ./ft_printf/ft_printf_hex.c ./ft_printf/ft_printf_ptr.c ./ft_printf/ft_printf_putnbr.c ./ft_printf/ft_printf_str.c \
       ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \

OBJS = ${SRCS:.c=.o}
LIBC = ar rc
RM = rm -f

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

libft/libft.a:
	@$(MAKE) -C libft

all: ${NAME}

clean:
	${RM} ${OBJS}
	@$(MAKE) -C libft clean

fclean: clean
	${RM} ${NAME}
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
