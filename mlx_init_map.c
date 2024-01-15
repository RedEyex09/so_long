/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:07:28 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/15 11:56:50 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int key_press, t_map_mlx *map)
{

	if(key_press >= 0)
		ft_printf("%s", map->map_info[1]);
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
	
	map->i = 60;
	map->j = 60;
	if (c == '1')
	{
		map->new_img_wall = mlx_xpm_file_to_image(map->mlx, "src/wall.xpm",
					&map->i, &map->j);
		map_mlx_img_set(map, map->new_img_wall);
	}
	else if (c == 'P')
	{
		map->new_img_player = mlx_xpm_file_to_image(map->mlx, "src/player.xpm",
					&map->i, &map->j);
		map_mlx_img_set(map, map->new_img_player);
	}
	return(0);
}
int map_mlx_check_2(char c, t_map_mlx *map)
{
	
	map->i = 60;
	map->j = 60;
	if (c == 'C')
	{
		map->new_img_food = mlx_xpm_file_to_image(map->mlx, "src/food.xpm",
					&map->i, &map->j);
		map_mlx_img_set(map, map->new_img_food);
		
	}
	else if (c == 'E')
	{
		map->new_img_exit = mlx_xpm_file_to_image(map->mlx, "src/exit.xpm",
					&map->i, &map->j);
		map_mlx_img_set(map, map->new_img_exit);
	}
	return(0);
}

int map_mlx_read(t_map_mlx *map)
{
	
	map->map_info = ft_split(map->map_line, '\n');
	map->win = mlx_new_window(map->mlx, map->len * 60, map->counter * 60, "test wimdow");
	while (map->map_info[map->y])
	{
		map->x = 0;
		while (map->map_info[map->y][map->x])
		{
			if (map->map_info[map->y][map->x] == '1' || map->map_info[map->y][map->x] == 'P')
			{
				map_mlx_check_1(map->map_info[map->y][map->x], map);
			}
			else if (map->map_info[map->y][map->x] == 'C' || map->map_info[map->y][map->x] == 'E')
			{
				map_mlx_check_2(map->map_info[map->y][map->x], map);
			}
			map->x++;
		}
		map->y++;
	}
	return (0);
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
	map_mlx_read(map);
	return(0);
}
int	mlx_init_map(char *str)
{
	t_map_mlx	map;

	ft_memset(&map, 0, sizeof(map));
	map.i = 60;
	map.j = 60;
	map.mlx = mlx_init();
	
	map_read(str, &map);
	
	mlx_key_hook(map.win, key_hook, &map);
	mlx_loop(map.mlx);
	return(0);
}
