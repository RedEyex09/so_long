/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:07:28 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/16 15:47:43 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook_left(t_map_mlx *map)
{
	if (map->c == 0 && map->map_info[map->py][map->px - 1] != '1')
	{ 
		if(map->map_info[map->py][map->px - 1] == 'E')
			exit(0);
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py][map->px - 1] = 'P';
		map->e++;
		map_mlx_read(map, 1);
	}
	else if(map->map_info[map->py][map->px - 1] == '0' || map->map_info[map->py][map->px - 1] == 'C')
		{
			if (  map->map_info[map->py][map->px - 1] == 'C')
			 map->c--;
			map->map_info[map->py][map->px] = '0';
			map->map_info[map->py][map->px - 1] = 'P';
			map->e++;
			map_mlx_read(map, 1);
		}
	return(0);
}
int key_hook_down(t_map_mlx *map)
{
	if (map->c == 0 && map->map_info[map->py + 1][map->px] != '1')
	{ 
		if(map->map_info[map->py + 1][map->px] == 'E')
			exit(0);
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py + 1][map->px] = 'P';
		map->e++;
		map_mlx_read(map, 1);
	}
	else if(map->map_info[map->py + 1][map->px] == '0' || map->map_info[map->py + 1][map->px] == 'C')
		{
			if (  map->map_info[map->py + 1][map->px] == 'C')
			 map->c--;
			map->map_info[map->py][map->px] = '0';
			map->map_info[map->py + 1][map->px] = 'P';
			map->e++;
			map_mlx_read(map, 1);
		}
	
	return(0);
}
int key_hook_right(t_map_mlx *map)
{
	if (map->c == 0 && map->map_info[map->py][map->px + 1]!= '1')
	{ 
		if(map->map_info[map->py][map->px + 1] == 'E')
			exit(0);
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py][map->px + 1] = 'P';
		map->e++;
		map_mlx_read(map, 1);
	}
	else if(map->map_info[map->py][map->px + 1] == '0' || map->map_info[map->py][map->px + 1] == 'C')
		{
			if (map->map_info[map->py][map->px + 1] == 'C')
			 map->c--;
			map->map_info[map->py][map->px] = '0';
			map->map_info[map->py][map->px + 1] = 'P';
			map->e++;
			map_mlx_read(map, 1);
		}

	return (0);
}
int key_hook_up(t_map_mlx *map)
{
	if (map->c == 0 && map->map_info[map->py - 1][map->px]!= '1')
	{ 
		if(map->map_info[map->py - 1][map->px] == 'E')
			exit(0);
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py - 1][map->px] = 'P';
		map_mlx_read(map, 1);
	}
	else if(map->map_info[map->py - 1][map->px] == '0' || map->map_info[map->py - 1][map->px] == 'C')
		{
			if ( map->map_info[map->py - 1][map->px] == 'C')
			 map->c--;
			map->map_info[map->py][map->px] = '0';
			map->map_info[map->py -1][map->px] = 'P';
			map_mlx_read(map, 1);
			map->e++;
		}
		
	return(0);
}

int key_hook(int key_press, t_map_mlx *map)
{
	if (key_press == 53)
		exit(0);
	else if(key_press == 13 || key_press == 126)
		key_hook_up(map);
	else if(key_press == 0 || key_press == 123)
		key_hook_left(map);
	else if(key_press == 1 || key_press == 125)
		key_hook_down(map);
	else if(key_press == 2 || key_press == 124)
		key_hook_right(map);
	ft_printf("Player Moves -> %d\n", map->e);
	ft_printf("How much food left : %d\n", map->c);
	return(0);
}
int map_mlx_img_set(t_map_mlx *map, char *img)
{

	int xx = map->x * 60;
	int yy = map->y * 60;
	mlx_put_image_to_window(map->mlx, map->win, img, xx, yy);
	return (0);
}

int map_mlx_check_1(char c, t_map_mlx *map)
{
	if (c == '1')
		map_mlx_img_set(map, map->new_img_wall);
	else if (c == 'P')
		map_mlx_img_set(map, map->new_img_player);
	return(0);
}
int map_mlx_check_2(char c, t_map_mlx *map)
{
	if (c == 'C')
		map_mlx_img_set(map, map->new_img_food);
	else if (c == 'E')
		map_mlx_img_set(map, map->new_img_exit);
	return(0);
}

int map_mlx_read(t_map_mlx *map, int i)
{
	if(i == 0)
		map->map_info = ft_split(map->map_line, '\n');
	map->y = 0;
	mlx_clear_window(map->mlx, map->win);
	while (map->map_info[map->y])
	{
		map->x = 0;
		while (map->map_info[map->y][map->x])
		{
			if (map->map_info[map->y][map->x] == '1' || map->map_info[map->y][map->x] == 'P')
			{
				if (map->map_info[map->y][map->x] == 'P')
				{
					map->px = map->x;
					map->py = map->y;
				}
				map_mlx_check_1(map->map_info[map->y][map->x], map);
			}
			else if (map->map_info[map->y][map->x] == 'C' || map->map_info[map->y][map->x] == 'E')
				map_mlx_check_2(map->map_info[map->y][map->x], map);
			map->x++;
		}
		map->y++;
	}
	return (0);
}
int c_counter(char *str)
{
	int i = 0;
	int c = 0;
	while(str[i])
	{
		if (str[i]== 'C')
			c++;
		i++;	
	}
	return(c);
}
int map_len_validation(t_map_mlx *map)
{
	if(map->len < 43 && map->counter <= 23)
		map->win = mlx_new_window(map->mlx, map->len * 60, map->counter * 60, "test wimdow");
	else
	{
		ft_printf("SIZE OF MAP TOO BIG FOR SCREEN\n");
		exit(0);
	}
	return(0);
}

int map_read(char *str , t_map_mlx *map)
{
	map->fd = open(str, O_RDONLY);
	if (map->fd <= 0)
		return (ft_printf("eroor"), 0);
	map->buffer = ft_strdup("");
	map->map_line = ft_strdup("");
	while (1)
	{
		map->buffer = get_next_line(map->fd);
		if (map->buffer == NULL)
			break ;
		if (map->counter == 0)
			map->len = ft_strlen(map->buffer);
		map->counter++;
		map->tmp = map->map_line;
		map->map_line = ft_strjoin(map->tmp, map->buffer);
		free(map->tmp);
		map->tmp = NULL;
		free(map->buffer);
		map->buffer = NULL;
	}
	map->len--;
	map->c = c_counter (map->map_line);
	map_len_validation(map);
	map->win = mlx_new_window(map->mlx, map->len * 60, map->counter * 60, "test wimdow");
	map_mlx_read(map, 0);
	return(0);
}
int	mlx_init_map(char *str)
{
	t_map_mlx	map;

	ft_memset(&map, 0, sizeof(map));
	map.str_read = str;
	map.i = 60;
	map.j = 60;
	map.mlx = mlx_init();
	map.new_img_food = mlx_xpm_file_to_image(map.mlx, "src/food.xpm",
					&map.i, &map.j);
	map.new_img_exit = mlx_xpm_file_to_image(map.mlx, "src/exit.xpm",
					&map.i, &map.j);
	map.new_img_player = mlx_xpm_file_to_image(map.mlx, "src/player.xpm",
					&map.i, &map.j);
	map.new_img_wall = mlx_xpm_file_to_image(map.mlx, "src/wall.xpm",
					&map.i, &map.j);
	map_read(map.str_read, &map);
	
	mlx_hook(map.win, 2, 0, key_hook, &map);
	mlx_loop(map.mlx);
	return(0);
}
