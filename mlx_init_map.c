/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:07:28 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/15 15:54:32 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int key_hook(int key_press, t_map_mlx *map)
{

	if(key_press == 13 || key_press == 126)
	{
		map->map_info[map->py][map->px] = '0';
		map->py -= 1;
		map->map_info[map->py][map->px] = 'P';
		ft_printf("UP\n");
		// mlx_destroy_image(map->mlx, map->new_img_player);
		map_mlx_read(map, 1);
		ft_printf("doone\n");
	}
	else if(key_press == 0 || key_press == 123)
		ft_printf("LEFT\n");
	else if(key_press == 1 || key_press == 125)
		ft_printf("DOWN\n");
	else if(key_press == 2 || key_press == 124)
		ft_printf("RIGHT\n");
	ft_printf("xp :%d  yp : %d\n", map->px, map->py);
	return(map->len2);
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
	
	map_read(map.str_read, &map);
	
	mlx_key_hook(map.win, key_hook, &map);
	mlx_loop(map.mlx);
	return(0);
}
