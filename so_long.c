/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:37:58 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/08 16:22:31 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_last(char *str,size_t len)
{
	t_map_check wall;
	
	wall.counter= 0;
	while(str[wall.counter])
		wall.counter++;
	size_t i =0;
	i = wall.counter - len;
	i++;
	while(str[i])
	{
		if(str[i] != '1')
		{
			printf("last line invalid\n");
			return (0);
		}
		i++;
	}
	// printf("i : %zu\n", i);
	// printf("last : %zu \n",wall.counter);
	// printf("len : %zu \n",len);
	return(1);
}
int map_first(char *str, size_t counter, size_t len)
{
	t_map_check wall;
	
	wall.counter= 0;
	while(str[wall.counter] != '\n' && str[wall.counter] != '\0')
	{
		if(str[wall.counter] != '1')
		{
			printf("Fist line invalid\n");
			return (0);
		}
		wall.counter++;
		
	}
	wall.len =(len * counter) - 1;
	if (map_last(str, len - 1) == 1)
		return (1);
	return(0);
}

int map_wall_checker(char *str, size_t counter, size_t len)
{
	t_map_check	wall;
	
	wall.counter = 0;
	wall.counter2 = 0;
	wall.len = 0;
	if(map_first(str, counter, len))
	{
		while(counter > 0)
		{

			wall.len++;
			if(str[wall.counter] == '\n' || str[wall.counter] == '\0')
			{
				if(str[wall.counter2] == '1' && str[wall.counter - 1] == '1'
				 && len  == wall.len)
				{
					wall.counter2 = wall.counter + 1;
					counter--;
					wall.len = 0;
				}
				else
				{
					printf("not a valid wall\n");
					return(0);
				}
			}
			wall.counter++;
		}
	}
	return(1);
}

int new_line_checker(char *str)
{
	t_map_check new;

	new.counter = 0;
	while(str[new.counter])
	{
		if(str[new.counter] == '\n' && str[new.counter + 1] == '\n')
		{
			printf("there is a new line\n");
				return (0);
		}
		new.counter++;
	}
	return(1);
}
int map_checker(void)
{
	t_map_check map;
	
	map.len = 0;
	map.counter = 0;
	map.fd = open("maps/map1.ber", O_RDONLY);
	map.buffer = ft_strdup(""); 
	map.map_line = ft_strdup(""); 
	while(1)
	{
		map.buffer = get_next_line(map.fd);
		if(map.buffer == NULL)
			break;
		if(map.counter == 0)
			map.len = ft_strlen(map.buffer);
		map.counter++;
		map.tmp = map.map_line;
		map.map_line = ft_strjoin(map.tmp, map.buffer);
		free(map.tmp);
		map.tmp = NULL;
		free(map.buffer);
		map.buffer= NULL;
	}
	if(new_line_checker(map.map_line) && map_wall_checker(map.map_line, map.counter, map.len))
	{
		map.trim_line = ft_strtrim(map.map_line, "\n01EPC");
		if (map.trim_line[0] == '\0')
			return (1);
	}
	return(0);
}


int main() {
    int result = map_checker();
    if (result == 1) {
        ft_printf("Valid map\n");
    } else {
        ft_printf("Not a valid map\n");
    }
	
    return 0;
}