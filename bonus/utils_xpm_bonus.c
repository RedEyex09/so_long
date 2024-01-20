/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_xpm_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:32:50 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/20 18:10:55 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mlx_player_init(t_map_mlx *map)
{
	map->new_img_player_up = mlx_xpm_file_to_image(map->mlx,
			"src/player_up.xpm", &map->i, &map->j);
	map->new_img_player_down = mlx_xpm_file_to_image(map->mlx,
			"src/player_down.xpm", &map->i, &map->j);
	map->new_img_player_right = mlx_xpm_file_to_image(map->mlx,
			"src/player_right.xpm", &map->i, &map->j);
	map->new_img_player_left = mlx_xpm_file_to_image(map->mlx,
			"src/player_left.xpm", &map->i, &map->j);
	if (!map->new_img_player_up || !map->new_img_player_down
		|| !map->new_img_player_right || !map->new_img_player_left)
	{
		ft_printf("Error\nPoblem in image instialisation of player\n");
		exit(0);
	}
}

int	map_mlx_img_set_player(t_map_mlx *map)
{
	int	xx;
	int	yy;

	yy = map->y * 60;
	xx = map->x * 60;
	if (map->ps == 0 || map->ps == 1)
		mlx_put_image_to_window(map->mlx, map->win,
			map->new_img_player_down, xx, yy);
	else if (map->ps == 2)
		mlx_put_image_to_window(map->mlx, map->win,
			map->new_img_player_up, xx, yy);
	else if (map->ps == 3)
		mlx_put_image_to_window(map->mlx, map->win,
			map->new_img_player_right, xx, yy);
	else if (map->ps == 4)
		mlx_put_image_to_window(map->mlx, map->win,
			map->new_img_player_left, xx, yy);
	return (0);
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
