/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_xpm_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:32:50 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/24 13:17:58 by hel-magh         ###   ########.fr       */
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

void	mlx_enemy_init(t_map_mlx *map)
{
	map->new_img_monster_up = mlx_xpm_file_to_image(map->mlx,
			"src/monster_up.xpm", &map->i, &map->j);
	map->new_img_monster_down = mlx_xpm_file_to_image(map->mlx,
			"src/monster_down.xpm", &map->i, &map->j);
	map->new_img_monster_right = mlx_xpm_file_to_image(map->mlx,
			"src/monster_right.xpm", &map->i, &map->j);
	map->new_img_monster_left = mlx_xpm_file_to_image(map->mlx,
			"src/monster_left.xpm", &map->i, &map->j);
	if (!map->new_img_monster_up || !map->new_img_monster_down
		|| !map->new_img_monster_right || !map->new_img_monster_left)
	{
		ft_printf("Error\nPoblem in image instialisation of enemy\n");
		exit(0);
	}
}

int	map_mlx_img_set_enemy(t_map_mlx *map)
{
	int	xx;
	int	yy;

	yy = map->y * 60;
	xx = map->x * 60;
	if (map->ns == 0 || map->ns == 1)
		mlx_put_image_to_window(map->mlx, map->win,
			map->new_img_monster_down, xx, yy);
	else if (map->ns == 2)
		mlx_put_image_to_window(map->mlx, map->win,
			map->new_img_monster_up, xx, yy);
	else if (map->ns == 3)
		mlx_put_image_to_window(map->mlx, map->win,
			map->new_img_monster_right, xx, yy);
	else if (map->ns == 4)
		mlx_put_image_to_window(map->mlx, map->win,
			map->new_img_monster_left, xx, yy);
	return (0);
}

void	win_lose(int c, t_map_mlx *map)
{
	if (c == 1)
	{
		ft_printf("WINNER\n");
		destroy_img_bonus(map);
	}
	else
	{
		ft_printf("YOU LOST\n");
		destroy_img_bonus(map);
	}
}
