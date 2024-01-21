/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_enemy_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:37:52 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/21 17:37:05 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_left(t_map_mlx *map)
{
	if (map->map_info[map->ny][map->nx - 1] == 'P')
		win_lose(0);
	map->map_info[map->ny][map->nx] = '0';
	map->map_info[map->ny][map->nx - 1] = 'N';
	map_mlx_read(map, 1);
	map_init_printer(map);
}

void	enemy_down(t_map_mlx *map)
{
	if (map->map_info[map->ny + 1][map->nx] == 'P')
		win_lose(0);
	map->map_info[map->ny][map->nx] = '0';
	map->map_info[map->ny + 1][map->nx] = 'N';
	map_mlx_read(map, 1);
	map_init_printer(map);
}

void	enemy_right(t_map_mlx *map)
{
	if (map->map_info[map->ny][map->nx + 1] == 'P')
		win_lose(0);
	map->map_info[map->ny][map->nx] = '0';
	map->map_info[map->ny][map->nx + 1] = 'N';
	map_mlx_read(map, 1);
	map_init_printer(map);
}

void	enemy_up(t_map_mlx *map)
{
	if (map->map_info[map->ny - 1][map->nx] == 'P')
		win_lose(0);
	map->map_info[map->ny][map->nx] = '0';
	map->map_info[map->ny - 1][map->nx] = 'N';
	map_mlx_read(map, 1);
	map_init_printer(map);
}
