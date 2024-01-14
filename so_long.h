/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:37:53 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/14 21:26:56 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libs/ft_printf/ft_printf.h"
# include "./libs/libft/libft.h"
# include "./libs/get_next_line/get_next_line.h"
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
}	t_map_check;

typedef struct map_mlx
{
	char	**map_info;
	char	*map_line;
	char	*buffer;
	char	*tmp;
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
	int		p;
	int		e;
	int		c;
	void	*mlx;
	void	*win;
	void	*new_img_wall;
	void	*new_img_player;
	void	*new_img_food;
	
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
int		map_final_check(char **spliteline);
int		mlx_init_map(char *str);

#endif