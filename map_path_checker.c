/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:15:06 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/13 20:08:30 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_final_check(char **spliteline)
{
	t_map_check	fill;

	ft_memset(&fill, 0, sizeof(fill));
	while (spliteline[fill.i])
	{
		fill.j = 0;
		while (spliteline[fill.i][fill.j])
		{
			if (spliteline[fill.i][fill.j] == '1'
					|| spliteline[fill.i][fill.j] == 'E')
				fill.j++;
			else
			{
				ft_printf("The Path isn't Valid\n");
				return (0);
			}
		}
		fill.i++;
	}
	return (1);
}

char	**map_flood_fill(size_t x, size_t y,
			char **spliteline, size_t map_counter)
{
	t_map_check	fill;

	ft_memset(&fill, 0, sizeof(fill));
	if (x < 0 || x >= ft_strlen(*spliteline) || y < 0 || y >= map_counter
		|| spliteline[y][x] == '1' || spliteline[y][x] == 'E' )
		return (0);
	spliteline[y][x] = '1';
	map_flood_fill(x - 1, y, spliteline, map_counter);
	map_flood_fill(x + 1, y, spliteline, map_counter);
	map_flood_fill(x, y - 1, spliteline, map_counter);
	map_flood_fill(x, y + 1, spliteline, map_counter);
	return (spliteline);
}

int	map_position_check(char **split_line, size_t map_counter)
{
	t_map_check	fill;

	ft_memset(&fill, 0, sizeof(fill));
	while (split_line[fill.i])
	{
		fill.j = 0;
		while (split_line[fill.i][fill.j])
		{
			if (split_line[fill.i][fill.j] == 'P')
			{
				fill.x = fill.j;
				fill.y = fill.i;
			}
			fill.j++;
		}
		fill.i++;
	}
	fill.split_line = map_flood_fill(fill.x, fill.y, split_line, map_counter);
	return (map_final_check(fill.split_line));
}
