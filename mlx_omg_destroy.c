/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_omg_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:53:47 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/22 18:16:02 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_map_mlx *map)
{
	mlx_destroy_image(map->mlx, map->new_img_food);
	mlx_destroy_image(map->mlx, map->new_img_exit);
	mlx_destroy_image(map->mlx, map->new_img_exit_open);
	mlx_destroy_image(map->mlx, map->new_img_wall);
	mlx_destroy_image(map->mlx, map->new_img_player);
}

void	ft_close_mlx(t_map_mlx *map)
{
	ft_printf("Error\nProblem in file descriptor\n");
	close (map->fd);
	destroy_img(map);
	exit(0);
}
