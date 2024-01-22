/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_omg_destroy_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:53:47 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/22 18:57:59 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_img_bonus(t_map_mlx *map)
{
	mlx_destroy_image(map->mlx, map->new_img_food);
	mlx_destroy_image(map->mlx, map->new_img_exit);
	mlx_destroy_image(map->mlx, map->new_img_exit_open);
	mlx_destroy_image(map->mlx, map->new_img_wall);
	mlx_destroy_image(map->mlx, map->new_img_player_up);
	mlx_destroy_image(map->mlx, map->new_img_player_down);
	mlx_destroy_image(map->mlx, map->new_img_player_left);
	mlx_destroy_image(map->mlx, map->new_img_player_right);
	mlx_destroy_image(map->mlx, map->new_img_monster_up);
	mlx_destroy_image(map->mlx, map->new_img_monster_down);
	mlx_destroy_image(map->mlx, map->new_img_monster_right);
	mlx_destroy_image(map->mlx, map->new_img_monster_left);
	exit(0);
}

void	ft_close_mlx(t_map_mlx *map)
{
	ft_printf("Error\nProblem in file descriptor\n");
	close (map->fd);
	destroy_img_bonus(map);
}
