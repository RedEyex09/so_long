/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mlx_imgs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:43:37 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/20 11:00:57 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	map_mlx_img_set(t_map_mlx *map, char *img)
{
	int	xx;
	int	yy;

	yy = map->y * 60;
	xx = map->x * 60;
	mlx_put_image_to_window(map->mlx, map->win, img, xx, yy);
	return (0);
}

int	map_mlx_check_1(char c, t_map_mlx *map, int x, int y)
{
	if (c == '1')
		map_mlx_img_set(map, map->new_img_wall);
	else if (c == 'P')
	{
		map->px = x;
		map->py = y;
		map_mlx_img_set_player(map);
	}
	else if (map->map_info[map->y][map->x] == 'C'
				|| map->map_info[map->y][map->x] == 'E')
		map_mlx_check_2(map->map_info[map->y][map->x], map);
	return (0);
}

int	map_mlx_check_2(char c, t_map_mlx *map)
{
	if (c == 'C')
		map_mlx_img_set(map, map->new_img_food);
	else if (c == 'E' && map->c > 0)
		map_mlx_img_set(map, map->new_img_exit);
	else if (c == 'E' && map->c == 0)
		map_mlx_img_set(map, map->new_img_exit_open);
	return (0);
}

int	map_mlx_read(t_map_mlx *map, int i)
{
	if (i == 0)
		map->map_info = ft_split(map->map_line, '\n');
	map->y = 0;
	mlx_clear_window(map->mlx, map->win);
	while (map->map_info[map->y])
	{
		map->x = 0;
		while (map->map_info[map->y][map->x])
		{
			if (map->map_info[map->y][map->x] == '1'
				|| map->map_info[map->y][map->x] == 'P'
				||map->map_info[map->y][map->x] == 'C'
				|| map->map_info[map->y][map->x] == 'E')
			{
				map_mlx_check_1(map->map_info[map->y][map->x],
					map, map->x, map->y);
			}
			map->x++;
		}
		map->y++;
	}
	return (0);
}
