/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:37:58 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/22 09:15:02 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	new_line_checker(char *str)
{
	t_map_check	new;

	ft_memset(&new, 0, sizeof(new));
	while (str[new.counter])
	{
		if (str[new.counter] == '\n' && str[new.counter + 1] == '\n')
		{
			ft_printf("Error\nThere is a new line\n");
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
		if (!map.split_line)
			return (free(map_line), 0);
		if (map_position_check(map.split_line, map_counter))
		{
			map.trim_line = ft_strtrim(map_line, "\n01ENPC");
			if (!map.split_line)
				return (free(map_line), \
				ft_free_double(map.split_line, map_counter), 0);
			if (map.trim_line[0] == '\0')
			{
				ft_free_double(map.split_line, map_counter);
				return (ft_free(map_line), ft_free(map.trim_line), 1);
			}
		}
	}
	return (ft_free(map_line), 0);
}

void	ft_close(int fd)
{
	ft_printf("Error\nProblem in file descriptor\n");
	close (fd);
	exit(0);
}

int	map_checker(char *str)
{
	t_map_check	map;

	ft_memset(&map, 0, sizeof(map));
	map_name_check(str);
	map.fd = open(str, O_RDONLY);
	if (map.fd <= 0)
		ft_close(map.fd);
	map.map_line = ft_strdup("");
	if (!map.map_line)
		return (0);
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
		ft_free(map.tmp);
		ft_free(map.buffer);
	}
	ft_free(map.buffer);
	return (map_checker_2(map.map_line, map.counter, map.len));
}
