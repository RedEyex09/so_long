/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:54:44 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/09 15:11:30 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_content_checker(char *str)
{
	t_map_check	content;

	ft_memset(&content, 0, sizeof(content));
	while (str[content.counter2])
	{
		if (str[content.counter2] == 'P')
			content.p++;
		else if (str[content.counter2] == 'E')
			content.e++;
		else if (str[content.counter2] == 'C')
			content.c++;
		content.counter2++;
	}
	if (content.p != 1 || content.e != 1 || content.c <= 0)
	{
		ft_printf("Not a valid content EPC\n");
		return (0);
	}
	return (1);
}

int	map_last(char *str, size_t len)
{
	t_map_check	wall;

	ft_memset(&wall, 0, sizeof(wall));
	while (str[wall.counter])
		wall.counter++;
	wall.i = wall.counter - len;
	wall.i++;
	while (str[wall.i])
	{
		if (str[wall.i] != '1')
		{
			ft_printf("last line invalid\n");
			return (0);
		}
		wall.i++;
	}
	return (1);
}

int	map_first(char *str, size_t counter, size_t len)
{
	t_map_check	wall;

	ft_memset(&wall, 0, sizeof(wall));
	while (str[wall.counter] != '\n' && str[wall.counter] != '\0')
	{
		if (str[wall.counter] != '1')
		{
			ft_printf("Fist line invalid\n");
			return (0);
		}
		wall.counter++;
	}
	wall.len = (len * counter) - 1;
	if (map_last(str, len - 1) == 1)
		return (1);
	return (0);
}

int	map_wall_checker(char *str, size_t counter, size_t len)
{
	t_map_check	wall;

	ft_memset(&wall, 0, sizeof(wall));
	if (map_first(str, counter, len))
	{
		while (counter > 0)
		{
			wall.len++;
			if (str[wall.counter] == '\n' || str[wall.counter] == '\0')
			{
				if (str[wall.counter2] == '1' && str[wall.counter - 1] == '1'
					&& len == wall.len)
				{
					wall.counter2 = wall.counter + 1;
					counter--;
					wall.len = 0;
				}
				else
					return (ft_printf("not valid walls\n"), 0);
			}
			wall.counter++;
		}
	}
	return (1);
}


