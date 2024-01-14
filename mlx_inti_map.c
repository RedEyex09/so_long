/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_inti_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:07:28 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/14 13:26:54 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_init_map(char *str)
{
	t_map_mlx	map;

	ft_memset(&map, 0, sizeof(map));
	map.x = 60;
	map.y = 60;
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 500, 500, "test wimdow");
	map.new_img_wall = mlx_xpm_file_to_image(map.mlx, "src/wall.xpm",
			&map.x, &map.y);
	map.new_img_player = mlx_xpm_file_to_image(map.mlx, "src/player.xpm",
			&map.x, &map.y);
	map.fd = open(str, O_RDONLY);
	
	mlx_put_image_to_window(map.mlx, map.win, map.new_img_wall, 0, 0);
	mlx_loop(map.mlx);

	
}