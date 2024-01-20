/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:54:44 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/20 11:27:31 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		else if (str[content.counter2] == 'N')
			content.n++;
		content.counter2++;
	}
	if (content.p != 1 || content.e != 1 || content.c <= 0
		|| content.n <= 0)
	{
		ft_printf("Error\nNot a valid content NEPC\n");
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
			ft_printf("Error\nThe Last line is invalid\n");
			exit(0);
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
			ft_printf("Error\n The Fist line is invalid\n");
			exit(0);
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
					return (ft_printf("Error\nNot valid walls\n"), 0);
			}
			wall.counter++;
		}
	}
	return (1);
}

int	map_name_check(char *str)
{
	int	i;
	int	v;

	i = 0;
	v = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == 'b')
		{
			if (str[i + 2] == 'e' && str[i + 3] == 'r')
			{
				if (str[i + 4] == '\0')
					v = 1;
			}
		}
		i++;
	}
	if (!v)
	{
		ft_printf("Error\nNot a valid .ber\n");
		exit(0);
	}
	return (0);
}
