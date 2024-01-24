/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_checker_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:15:06 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/24 20:59:36 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	notify(t_map_mlx *map)
{
	ft_printf("Exit X\n");
	destroy_img_bonus(map);
	return (0);
}

int	map_final_check(char **spliteline, size_t map_counter)
{
	t_map_check	fill;

	ft_memset(&fill, 0, sizeof(fill));
	while (spliteline[fill.i])
	{
		fill.j = 0;
		while (spliteline[fill.i][fill.j])
		{
			if (spliteline[fill.i][fill.j] == 'C'
				|| spliteline[fill.i][fill.j] == '0')
			{
				ft_printf("Error\nThe Path isn't Valid\n");
				ft_free_double(spliteline, map_counter);
				return (0);
			}
			fill.j++;
		}
		fill.i++;
	}
	ft_free_double(spliteline, map_counter);
	return (1);
}

int	ft_prtotect(char **spliteline, size_t x, size_t y)
{
	if ((spliteline[y][x] == 'C')
		&& ((spliteline[y + 1][x] == 'E' && spliteline[y - 1][x] == '1'
		&& spliteline[y][x + 1] == '1' && spliteline[y][x - 1] == '1') ||
		(spliteline[y - 1][x] == 'E' && spliteline[y + 1][x] == '1'
		&& spliteline[y][x + 1] == '1' && spliteline[y][x - 1] == '1')
		|| (spliteline[y][x + 1] == 'E' && spliteline[y + 1][x] == '1'
		&& spliteline[y - 1][x] == '1' && spliteline[y][x - 1] == '1')
		|| (spliteline[y][x - 1] == 'E' && spliteline[y + 1][x] == '1'
		&& spliteline[y - 1][x] == '1' && spliteline[y][x + 1] == '1')))
	{
		return (1);
	}
	return (0);
}

char	**map_flood_fill(size_t x, size_t y,
			char **spliteline, size_t map_counter)
{
	t_map_check	fill;

	ft_memset(&fill, 0, sizeof(fill));
	if (x < 0 || x >= ft_strlen(*spliteline) || y < 0 || y >= map_counter
		|| spliteline[y][x] == '1' || spliteline[y][x] == 'E')
		return (0);
	if (ft_prtotect(spliteline, x, y))
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
	exit_check(split_line, map_counter);
	fill.split_line = map_flood_fill(fill.x, fill.y, split_line, map_counter);
	return (map_final_check(fill.split_line, map_counter));
}
