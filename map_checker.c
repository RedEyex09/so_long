/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:37:58 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/09 14:55:55 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		map.trim_line = ft_strtrim(map_line, "\n01EPC");
		if (map.trim_line[0] == '\0')
			return (1);
	}
	return (0);
}

int	map_checker(void)
{
	t_map_check	map;

	ft_memset(&map, 0, sizeof(map));
	map.fd = open("maps/map1.ber", O_RDONLY);
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
