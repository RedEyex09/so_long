/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:37:53 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/20 18:09:17 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libs/ft_printf/ft_printf.h"
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"
# include <mlx.h>
# include <libc.h>
# include <limits.h>
# include <fcntl.h>

typedef struct map_check
{
	char	*map_line;
	char	*buffer;
	char	*trim_line;
	char	*tmp;
	char	**split_line;
	char	character;
	char	character2;
	size_t	counter;
	size_t	len;
	size_t	len2;
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	y;
	size_t	counter2;
	int		fd;
	int		p;
	int		e;
	int		c;
	int		n;
}	t_map_check;

typedef struct map_mlx
{
	char	**map_info;
	char	*map_line;
	char	*buffer;
	char	*tmp;
	char	*str_read;
	char	*player_move;
	char	character;
	char	character2;
	int		counter;
	size_t	len;
	size_t	len2;
	int		i;
	int		j;
	int		x;
	int		y;
	int		fd;
	int		px;
	int		py;
	int		nx;
	int		ny;
	int		ps;
	int		e;
	int		c;
	int		pr;
	void	*mlx;
	void	*win;
	void	*new_img_wall;
	void	*new_img_player_up;
	void	*new_img_player_down;
	void	*new_img_player_right;
	void	*new_img_player_left;
	void	*new_img_monster;
	void	*new_img_food;
	void	*new_img_exit;
	void	*new_img_exit_open;
}	t_map_mlx;

int		map_checker(char *str);
int		map_checker_2(char *map_line, size_t map_counter, size_t map_len);
int		new_line_checker(char *str);
int		map_wall_checker(char *str, size_t counter, size_t len);
int		map_first(char *str, size_t counter, size_t len);
int		map_last(char *str, size_t len);
int		map_content_checker(char *str);
int		map_position_check(char **split_line, size_t map_counter);
char	**map_flood_fill(size_t x, size_t y,
			char **spliteline, size_t map_counter);
int		map_final_check(char **spliteline, size_t map_counter);
void	mlx_init_map(char *str);
int		map_mlx_read(t_map_mlx *map, int i);
int		map_mlx_img_set(t_map_mlx *map, char *img);
int		map_read(char *str, t_map_mlx *map);
int		map_name_check(char *str);
int		map_len_validation(t_map_mlx *map);
int		c_counter(char *str);
int		map_mlx_read(t_map_mlx *map, int i);
int		map_mlx_check_2(char c, t_map_mlx *map);
int		map_mlx_check_1(char c, t_map_mlx *map, int x, int y);
int		map_mlx_img_set(t_map_mlx *map, char *img);
int		key_hook(int key_press, t_map_mlx *map);
int		key_hook_up(t_map_mlx *map);
int		key_hook_right(t_map_mlx *map);
int		key_hook_down(t_map_mlx *map);
int		key_hook_left(t_map_mlx *map);
void	ft_free(char *str);
void	*ft_free_double(char **str, size_t count);
void	ft_close(int fd);
void	malx_img_init(t_map_mlx *map);
int		notify(t_map_mlx *map);
void	map_printer(t_map_mlx *map);
void	map_init_printer(t_map_mlx *map);
void	mlx_player_init(t_map_mlx *map);
int		map_mlx_img_set_player(t_map_mlx *map);
int		enemy(t_map_mlx *map);
int		enemy_up(t_map_mlx *map);
int		enemy_right(t_map_mlx *map);
int		enemy_down(t_map_mlx *map);
int		enemy_left(t_map_mlx *map);
void	win_lose(int c);

#endif