/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:37:53 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/10 11:05:37 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
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

int	map_checker(void);
int	map_checker_2(char *map_line, size_t map_counter, size_t map_len);
int	new_line_checker(char *str);
int	map_wall_checker(char *str, size_t counter, size_t len);
int	map_first(char *str, size_t counter, size_t len);
int	map_last(char *str, size_t len);
int	map_content_checker(char *str);

#endif