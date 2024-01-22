/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:06:43 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/22 19:00:02 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_printer(t_map_mlx *map)
{
	map->e++;
	map ->character = ft_itoa(map->e);
	if (!map ->character)
	{
		ft_printf("Error\n Counter problem");
		destroy_img_bonus(map);
	}
	map->player_move = ft_strjoin("Player movement -> ", map ->character);
	if (!map ->player_move)
	{
		ft_printf("Error\n Counter problem");
		free(map ->character);
		destroy_img_bonus(map);
	}
	mlx_string_put(map->mlx, map->win, 0, 0, 0xFFFF, map->player_move);
	ft_free(map->player_move);
	free(map ->character);
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
		map ->character = ft_itoa(map->e);
		if (!map ->character)
		{
			ft_printf("Error\n Counter problem");
			destroy_img_bonus(map);
		}
		map->player_move = ft_strjoin("Player movement -> ", map ->character);
		if (!map ->player_move)
		{
			ft_printf("Error\n Counter problem");
			free(map ->character);
			destroy_img_bonus(map);
		}
		mlx_string_put(map->mlx, map->win, 0, 0, 0xFFFF, map->player_move);
		ft_free(map->player_move);
		free(map ->character);
	}
	map->pr = 1;
}

int	is_somthing(char c)
{
	return (c == 'C' || c == 'N' || c == '0');
}

int	jj(int c)
{
	return (c == 4 || c == 0);
}

int	is_po(char c)
{
	return (c == 'P' || c == '0');
}
