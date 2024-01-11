/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:37:58 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/11 18:48:51 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_flood_fill_3(char **spliteline)
{
	t_map_check	fill;

	ft_memset(&fill, 0, sizeof(fill));
	while (spliteline[fill.i])
	{
		fill.j= 0;
		while(spliteline[fill.i][fill.j])
		{
			if(spliteline[fill.i][fill.j] == '1' || spliteline[fill.i][fill.j] == 'E')
				fill.j++;
			else
			{
				ft_printf("still a %c in the map\n", spliteline[fill.i][fill.j]);
				return (0);
			}
		}
		fill.i++;
	}
	return(1);
}
char	**map_flood_fill_2(size_t x, size_t y, char **spliteline, size_t map_counter)
{
	t_map_check	fill;

	ft_memset(&fill, 0, sizeof(fill));
	if (x < 0 || x >= ft_strlen(*spliteline) || y < 0 || y >= map_counter
		|| spliteline[y][x] == '1' || spliteline[y][x] == 'E' )
		return (0);
	spliteline[y][x] = '1';
	map_flood_fill_2(x - 1, y, spliteline, map_counter);
	map_flood_fill_2(x + 1, y, spliteline, map_counter);
	map_flood_fill_2(x, y - 1, spliteline, map_counter);
	map_flood_fill_2(x, y + 1, spliteline, map_counter);
	return (spliteline);
}
int	map_flood_fill(char **split_line, size_t map_counter)
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
	fill.split_line = map_flood_fill_2(fill.x, fill.y, split_line, map_counter);
	return (map_flood_fill_3(fill.split_line));
}

int	new_line_checker(char *str)
{
	t_map_check	new;

	ft_memset(&new, 0, sizeof(new));
	while (str[new.counter])
	{
		if (str[new.counter] == '\n' && str[new.counter + 1] == '\n')
		{
			ft_printf("there is a new line\n");
			return (0);
		}
		new.counter++;
	}
	return (1);
}

int	map_checker_2(char *map_line, size_t map_counter, size_t map_len)
{
	t_map_check	map;

	ft_memset(&map, 0, sizeof(map));
	if (new_line_checker(map_line)
		&& map_wall_checker(map_line, map_counter, map_len)
		&& map_content_checker(map_line))
	{
		map.split_line = ft_split(map_line, '\n');
		if(map_flood_fill(map.split_line, map_counter))
		{
			map.trim_line = ft_strtrim(map_line, "\n01EPC");
			if (map.trim_line[0] == '\0')
				return (1);
		}
	}
	return (0);
}

int	map_checker(void)
{
	t_map_check	map;

	ft_memset(&map, 0, sizeof(map));
	map.fd = open("maps/map1.ber", O_RDONLY);
	if (map.fd <= 0)
	{
		ft_printf("Problem in map file\n");
		exit(1);
	}
	map.buffer = ft_strdup("");
	map.map_line = ft_strdup("");
	while (1)
	{
		map.buffer = get_next_line(map.fd);
		if (map.buffer == NULL)
			break ;
		if (map.counter == 0)
			map.len = ft_strlen(map.buffer);
		map.counter++;
		map.tmp = map.map_line;
		map.map_line = ft_strjoin(map.tmp, map.buffer);
		free(map.tmp);
		map.tmp = NULL;
		free(map.buffer);
		map.buffer = NULL;
	}
	return (map_checker_2(map.map_line, map.counter, map.len));
}
