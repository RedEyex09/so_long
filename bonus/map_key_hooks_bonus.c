/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_key_hooks_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:47:28 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/22 18:54:57 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook_left(t_map_mlx *map)
{
	map->ps = 4;
	if (map->c == 0 && map->map_info[map->py][map->px - 1] != '1')
	{
		if (map->map_info[map->py][map->px - 1] == 'E')
			win_lose(1, map);
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py][map->px - 1] = 'P';
		map_mlx_read(map, 1);
		map_printer(map);
	}
	else if (is_somthing(map->map_info[map->py][map->px - 1]) == 1)
	{
		if (map->map_info[map->py][map->px - 1] == 'C')
			map->c--;
		if (map->map_info[map->py][map->px - 1] == 'N')
			win_lose(0, map);
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py][map->px - 1] = 'P';
		map_mlx_read(map, 1);
		map_printer(map);
	}
	return (0);
}

int	key_hook_down(t_map_mlx *map)
{
	map->ps = 1;
	if (map->c == 0 && map->map_info[map->py + 1][map->px] != '1')
	{
		if (map->map_info[map->py + 1][map->px] == 'E')
			win_lose(1, map);
		if (map->map_info[map->py + 1][map->px] == 'N')
			win_lose(0, map);
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py + 1][map->px] = 'P';
		map_mlx_read(map, 1);
		map_printer(map);
	}
	else if (is_somthing(map->map_info[map->py + 1][map->px]) == 1)
	{
		if (map->map_info[map->py + 1][map->px] == 'C')
			map->c--;
		if (map->map_info[map->py + 1][map->px] == 'N')
			win_lose(0, map);
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py + 1][map->px] = 'P';
		map_mlx_read(map, 1);
		map_printer(map);
	}
	return (0);
}

int	key_hook_right(t_map_mlx *map)
{
	map->ps = 3;
	if (map->c == 0 && map->map_info[map->py][map->px + 1] != '1')
	{
		if (map->map_info[map->py][map->px + 1] == 'E')
			win_lose(1, map);
		if (map->map_info[map->py][map->px + 1] == 'N')
			win_lose(0, map);
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py][map->px + 1] = 'P';
		map_mlx_read(map, 1);
		map_printer(map);
	}
	else if (is_somthing(map->map_info[map->py][map->px + 1]) == 1)
	{
		if (map->map_info[map->py][map->px + 1] == 'C')
			map->c--;
		if (map->map_info[map->py][map->px + 1] == 'N')
			win_lose(0, map);
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py][map->px + 1] = 'P';
		map_mlx_read(map, 1);
		map_printer(map);
	}
	return (0);
}

int	key_hook_up(t_map_mlx *map)
{
	map->ps = 2;
	if (map->c == 0 && map->map_info[map->py - 1][map->px] != '1')
	{
		if (map->map_info[map->py - 1][map->px] == 'E')
			win_lose(1, map);
		if (map->map_info[map->py - 1][map->px] == 'N')
			win_lose(0, map);
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py - 1][map->px] = 'P';
		map_mlx_read(map, 1);
		map_printer(map);
	}
	else if (is_somthing(map->map_info[map->py - 1][map->px]) == 1)
	{
		if (map->map_info[map->py - 1][map->px] == 'C')
			map->c--;
		if (map->map_info[map->py - 1][map->px] == 'N')
			win_lose(0, map);
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py -1][map->px] = 'P';
		map_mlx_read(map, 1);
		map_printer(map);
	}
	return (0);
}

int	key_hook(int key_press, t_map_mlx *map)
{
	if (key_press == 53)
	{
		ft_printf("Quitting ESC\n");
		destroy_img_bonus(map);
	}
	else if (key_press == 13 || key_press == 126)
		key_hook_up(map);
	else if (key_press == 0 || key_press == 123)
		key_hook_left(map);
	else if (key_press == 1 || key_press == 125)
		key_hook_down(map);
	else if (key_press == 2 || key_press == 124)
		key_hook_right(map);
	return (0);
}
