NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework AppKit
LIBS = ./libs/ft_printf/libftprintf.a ./libs/libft/libft.a \
	   ./libs/get_next_line/get_next_line.c ./libs/get_next_line/get_next_line_utils.c\

SRCS = 	main.c map_checker.c map_checker_2.c map_path_checker.c mlx_init_map.c\
		map_key_hooks.c map_mlx_imgs.c ft_free.c mlx_omg_destroy.c\

SRCS_BONUS = ./bonus/main_bonus.c ./bonus/map_checker_bonus.c ./bonus/map_checker_bonus2.c\
		./bonus/map_path_checker_bonus.c ./bonus/mlx_init_map_bonus.c ./bonus/map_key_hooks_bonus.c\
		./bonus/map_mlx_imgs_bonus.c ./bonus/ft_free_bonus.c ./bonus/utils_bonus.c\
		./bonus/utils_xpm_bonus.c ./bonus/utils_enemy.c ./bonus/utils_enemy_2.c ./bonus/mlx_omg_destroy_bonus.c\
	
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
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
	@echo "<< Compiling $(NAME) is  Finished >>"

bonus :lib_compile ${NAME} ${OBJS_BONUS}
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LINKS) $(LIBS) -o $(NAME)
	@echo "<< Compiling $(NAME) Bonus Finished >>"

clean:
	@echo "Start removing .. "
	@cd ./libs/libft && make clean
	@cd ./libs/ft_printf && make clean
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@echo "<< Removing File .o is finished >> "

fclean: clean
	@echo "Start Removing $(NAME)"
	@cd ./libs/libft && make fclean
	@cd ./libs/ft_printf && make fclean
	@rm -rf $(NAME)
	@echo "<< Remove $(NAME) finished >> "

re: fclean all

.PHONY: clean  lib_compile