/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:37:53 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/08 15:21:46 by hel-magh         ###   ########.fr       */
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
	char	character;
	size_t	counter;
    size_t	len;
	size_t	len2;
	size_t	counter2;
	int		fd;
}	t_map_check;



#endif