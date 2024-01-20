/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_key_hooks_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:47:28 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/19 21:32:12 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook_left(t_map_mlx *map)
{
	if (map->c == 0 && map->map_info[map->py][map->px - 1] != '1')
	{
		if (map->map_info[map->py][map->px - 1] == 'E')
		{
			ft_printf("WINNER\n");
			exit(0);
		}
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py][map->px - 1] = 'P';
		map_mlx_read(map, 1);
		map_printer(map);
	}
	else if (map->map_info[map->py][map->px - 1] == '0'
		|| map->map_info[map->py][map->px - 1] == 'C')
	{
		if (map->map_info[map->py][map->px - 1] == 'C')
			map->c--;
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py][map->px - 1] = 'P';
		map_mlx_read(map, 1);
		map_printer(map);
	}
	return (0);
}

int	key_hook_down(t_map_mlx *map)
{
	if (map->c == 0 && map->map_info[map->py + 1][map->px] != '1')
	{
		if (map->map_info[map->py + 1][map->px] == 'E')
		{
			ft_printf("WINNER\n");
			exit(0);
		}
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py + 1][map->px] = 'P';
		map_mlx_read(map, 1);
		map_printer(map);
	}
	else if (map->map_info[map->py + 1][map->px] == '0'
		|| map->map_info[map->py + 1][map->px] == 'C')
	{
		if (map->map_info[map->py + 1][map->px] == 'C')
			map->c--;
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py + 1][map->px] = 'P';
		map_mlx_read(map, 1);
		map_printer(map);
	}
	return (0);
}

int	key_hook_right(t_map_mlx *map)
{
	if (map->c == 0 && map->map_info[map->py][map->px + 1] != '1')
	{
		if (map->map_info[map->py][map->px + 1] == 'E')
		{
			ft_printf("WINNER\n");
			exit(0);
		}
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py][map->px + 1] = 'P';
		map_mlx_read(map, 1);
		map_printer(map);
	}
	else if (map->map_info[map->py][map->px + 1] == '0'
		|| map->map_info[map->py][map->px + 1] == 'C')
	{
		if (map->map_info[map->py][map->px + 1] == 'C')
			map->c--;
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py][map->px + 1] = 'P';
		map_mlx_read(map, 1);
		map_printer(map);
	}
	return (0);
}

int	key_hook_up(t_map_mlx *map)
{
	if (map->c == 0 && map->map_info[map->py - 1][map->px] != '1')
	{
		if (map->map_info[map->py - 1][map->px] == 'E')
		{
			ft_printf("WINNER\n");
			exit(0);
		}
		map->map_info[map->py][map->px] = '0';
		map->map_info[map->py - 1][map->px] = 'P';
		map_mlx_read(map, 1);
		map_printer(map);
	}
	else if (map->map_info[map->py - 1][map->px] == '0'
		|| map->map_info[map->py - 1][map->px] == 'C')
	{
		if (map->map_info[map->py - 1][map->px] == 'C')
			map->c--;
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
		exit(0);
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
