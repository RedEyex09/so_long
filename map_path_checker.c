/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:15:06 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/24 21:42:31 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	notify(t_map_mlx *map)
{
	ft_printf("Exit X\n");
	destroy_img(map);
	exit(0);
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
			if (spliteline[fill.i][fill.j] == 'C')
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

char	**map_flood_fill(size_t x, size_t y,
			char **spliteline, size_t map_counter)
{
	if (spliteline[y][x] == '1' || spliteline[y][x] == 'E')
		return (0);
	spliteline[y][x] = 'P';
	if (spliteline[y][x - 1] == '0' || spliteline[y][x - 1] == 'C')
		map_flood_fill(x - 1, y, spliteline, map_counter);
	if (spliteline[y][x + 1] == '0' || spliteline[y][x + 1] == 'C')
		map_flood_fill(x + 1, y, spliteline, map_counter);
	if (spliteline[y - 1][x] == '0' || spliteline[y - 1][x] == 'C')
		map_flood_fill(x, y - 1, spliteline, map_counter);
	if (spliteline[y + 1][x] == '0' || spliteline[y + 1][x] == 'C')
		map_flood_fill(x, y + 1, spliteline, map_counter);
	return (spliteline);
}

void	exit_check(char **split_line, size_t map_counter)
{
	t_map_check	fill;

	ft_memset(&fill, 0, sizeof(fill));
	while (split_line[fill.i])
	{
		fill.j = 0;
		while (split_line[fill.i][fill.j])
		{
			if (split_line[fill.i][fill.j] == 'E')
			{
				if (split_line[fill.i + 1][fill.j] != 'P'
				&& split_line[fill.i - 1][fill.j] != 'P'
				&& split_line[fill.i][fill.j + 1] != 'P'
				&& split_line[fill.i][fill.j - 1] != 'P')
				{
					ft_printf("Error\nThe Path isn't Valid\n");
					ft_free_double(split_line, map_counter);
					exit(0);
				}
			}
			fill.j++;
		}
		fill.i++;
	}
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
	exit_check(split_line, map_counter);
	return (map_final_check(fill.split_line, map_counter));
}
