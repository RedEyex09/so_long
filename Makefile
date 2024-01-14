NAME = so_long.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework AppKit
LIBS = ./libs/ft_printf/libftprintf.a ./libs/libft/libft.a \
	   ./libs/get_next_line/get_next_line.c ./libs/get_next_line/get_next_line_utils.c\

SRCS = 	main.c map_checker.c map_checker_2.c map_path_checker.c mlx_init_map.c\
		
		
OBJS = ${SRCS:.c=.o}
LIBC = ar rc
RM = rm -f

all: lib_compile ${NAME}

lib_compile:
	@echo "compiling libs"
	@cd ./libs/libft && make
	@cd ./libs/ft_printf && make

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

${NAME}: ${OBJS}
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LINKS) $(LIBS) -o $(NAME)
	@echo "<< Compile finished >>"




clean:
	@echo "Start removing .. "
	@cd ./libs/libft && make clean
	@cd ./libs/ft_printf && make clean
	@rm -rf $(OBJS)
	@echo "<< Remove finished >> "

fclean: clean
	@echo "Start Removing $(NAME)"
	@cd ./libs/libft && make fclean
	@cd ./libs/ft_printf && make fclean
	@rm -rf $(NAME)
	@echo "<< Remove finished >> "

re: fclean all

.PHONY: all clean fclean re lib_compile