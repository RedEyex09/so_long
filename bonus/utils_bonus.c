/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:06:43 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/20 18:37:12 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_printer(t_map_mlx *map)
{
	map->e++;
	map->player_move = ft_strjoin("Player movement -> ", ft_itoa(map->e));
	mlx_string_put(map->mlx, map->win, 0, 0, 0xFFFF, map->player_move);
	ft_free(map->player_move);
}

void	map_init_printer(t_map_mlx *map)
{
	if (map->pr == 0)
	{
		map->player_move = "Player movement -> 0";
		mlx_string_put(map->mlx, map->win, 0, 0, 0xFFFFFF, map->player_move);
	}
	else
	{
		map->player_move = ft_strjoin("Player movement -> ", ft_itoa(map->e));
		mlx_string_put(map->mlx, map->win, 0, 0, 0xFFFF, map->player_move);
		ft_free(map->player_move);
	}
	map->pr = 1;
}

int	is_somthing(char c)
{
	return (c == 'C' || c == 'N' || c == '0');
}

void	win_lose(int c)
{
	if (c == 1)
	{
		ft_printf("WINNER\n");
		exit(0);
	}
	else
	{
		ft_printf("YOU LOST\n");
		exit(0);
	}
}
