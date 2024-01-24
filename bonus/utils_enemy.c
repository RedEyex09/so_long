/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:36:45 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/24 20:53:15 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	enemy_left_1(t_map_mlx *p, int j)
{
	enemy_left(p);
	if (p->map_info[p->ny][p->nx - 1] == '1')
	{
		enemy_right(p);
		j = 1;
	}
	return (j);
}

int	enemy_up_1(t_map_mlx *p, int j)
{
	enemy_up(p);
	if (p->map_info[p->ny - 1][p->nx] == '1')
	{
		enemy_down(p);
		j = 2;
	}
	if (p->map_info[p->ny - 1][p->nx] == 'P')
	{
		enemy_down(p);
		j = 2;
	}
	return (j);
}

int	enemy_right_1(t_map_mlx *p, int j)
{
	enemy_right(p);
	if (p->map_info[p->ny][p->nx + 1] == '1')
	{
		enemy_left(p);
		j = 3;
	}
	return (j);
}

int	enemy_down_1(t_map_mlx *p, int j)
{
	enemy_down(p);
	if (p->map_info[p->ny + 1][p->nx] == '1')
	{
		enemy_up(p);
		j = 4;
	}
	return (j);
}

int	enemy(t_map_mlx *p)
{
	static int	i;
	static int	j;

	i++;
	if (i == 2000 && jj(j) == 1 && is_po(p->map_info[p->ny][p->nx - 1]) == 1)
		j = enemy_left_1(p, j);
	else if (i == 1500 && j == 1 && is_po(p->map_info[p->ny - 1][p->nx]) == 1)
		j = enemy_up_1(p, j);
	else if (i == 1020 && j == 2 && is_po(p->map_info[p->ny][p->nx + 1]) == 1)
		j = enemy_right_1(p, j);
	else if (i == 1700 && j == 3 && is_po(p->map_info[p->ny + 1][p->nx]) == 1)
		j = enemy_down_1(p, j);
	if (i == 2000)
		i = 0;
	return (1);
}
