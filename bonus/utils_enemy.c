/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:36:45 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/20 16:10:28 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	enemy_left(t_map_mlx *map)
{
	// if ( map->map_info[map->ny][map->nx - 1] == '1')
	// 	return (0);
		map->map_info[map->ny][map->nx] = '0';
		map->map_info[map->ny][map->nx - 1] = 'N';
		map_mlx_read(map, 1);
		map_init_printer(map);
	return(1);
}
int enemy_down(t_map_mlx *map)
{
	
		map->map_info[map->ny][map->nx] = '0';
		map->map_info[map->ny + 1][map->nx] = 'N';
		map_mlx_read(map, 1);
		map_init_printer(map);
		return (1);

}
int enemy_right(t_map_mlx *map)
{

		map->map_info[map->ny][map->nx] = '0';
		map->map_info[map->ny][map->nx + 1] = 'N';
		map_mlx_read(map, 1);
		map_init_printer(map);
		return(1);
}
int enemy_up(t_map_mlx *map)
{
	
		map->map_info[map->ny][map->nx] = '0';
		map->map_info[map->ny - 1][map->nx] = 'N';
		map_mlx_read(map, 1);
		map_init_printer(map);
	return(1);
}
int	enemy(t_map_mlx *map)
{
	static int	i;
	static int	j;
	
	i++;
	// if (i != 0)
	// 	return(0);
	
	if ( i == 2000 && (j == 4 || j == 0) && map->map_info[map->ny][map->nx - 1] == '0')
	{	
		enemy_left(map);
		if (map->map_info[map->ny][map->nx - 1] == '1')
			j = 1;
	}
	else if ( i == 2400 && j == 1 && map->map_info[map->ny - 1][map->nx] == '0')
	{	
		enemy_up(map);
		if (map->map_info[map->ny - 1][map->nx] == '1')
			j = 2;
	}
	else if (i == 2450 && j == 2 &&  map->map_info[map->ny][map->nx + 1] == '0')
	{	
		enemy_right(map);
		if  (map->map_info[map->ny][map->nx + 1] == '1')
			j = 3;

	}
	else if (i == 2509 && j == 3 && map->map_info[map->ny + 1][map->nx] == '0')
	{	
		enemy_down(map);
		 if (map->map_info[map->ny + 1][map->nx] == '0')
			j = 4;
	}
		if (i == 2509)
			i = 0;
		return(1);
}