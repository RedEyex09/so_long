NAME = so_long.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	map_checker.c map_checker_2.c map_path_checker.c\
		./ft_printf/ft_printf.c ./ft_printf/ft_printf_hex.c ./ft_printf/ft_printf_ptr.c\
		./ft_printf/ft_printf_putnbr.c ./ft_printf/ft_printf_str.c \
    	./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		./libft/ft_isalpha.c ./libft/ft_isdigit.c ./libft/ft_isalnum.c ./libft/ft_isascii.c \
		./libft/ft_isprint.c ./libft/ft_strlen.c ./libft/ft_memset.c ./libft/ft_bzero.c \
		./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_strlcpy.c ./libft/ft_strlcat.c \
		./libft/ft_calloc.c ./libft/ft_strdup.c ./libft/ft_toupper.c ./libft/ft_tolower.c \
		./libft/ft_strchr.c ./libft/ft_strncmp.c ./libft/ft_memchr.c ./libft/ft_memcmp.c \
		./libft/ft_strnstr.c ./libft/ft_atoi.c ./libft/ft_strrchr.c ./libft/ft_substr.c \
		./libft/ft_strjoin.c ./libft/ft_strtrim.c ./libft/ft_split.c ./libft/ft_itoa.c \
		./libft/ft_strmapi.c ./libft/ft_striteri.c ./libft/ft_putchar_fd.c \
		./libft/ft_putstr_fd.c ./libft/ft_putendl_fd.c ./libft/ft_putnbr_fd.c\
		
OBJS = ${SRCS:.c=.o}
LIBC = ar rc
RM = rm -f

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}



all: ${NAME}

clean:
	${RM} ${OBJS}
	@$(MAKE) -C libft clean

fclean: clean
	${RM} ${NAME}
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
