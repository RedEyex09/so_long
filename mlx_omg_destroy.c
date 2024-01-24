/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_omg_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:53:47 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/24 19:38:36 by hel-magh         ###   ########.fr       */
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
	mlx_destroy_window(map->mlx, map->win);
}

void	ft_close_mlx(t_map_mlx *map)
{
	ft_printf("Error\nProblem in file descriptor\n");
	close (map->fd);
	destroy_img(map);
	exit(0);
}

void	exit_check(char **split_line, size_t map_counter)
{
	t_map_check	fill;

	ft_memset(&fill, 0, sizeof(fill));
	while (split_line[fill.i])
	{
		fill.j = 0;
		while (split_line[fill.i][fill.j])
		{
			if (split_line[fill.i][fill.j] == 'E')
			{
				if (split_line[fill.i + 1][fill.j] == '1'
				&& split_line[fill.i - 1][fill.j] == '1'
				&& split_line[fill.i][fill.j + 1] == '1'
				&& split_line[fill.i][fill.j - 1] == '1')
				{
					ft_printf("Error\nThe Path isn't Valid\n");
					ft_free_double(split_line, map_counter);
					exit(0);
				}
			}
			fill.j++;
		}
		fill.i++;
	}
}
