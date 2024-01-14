/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:07:28 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/14 21:27:46 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_init_map(char *str)
{
	t_map_mlx	map;

	ft_memset(&map, 0, sizeof(map));
	map.i = 60;
	map.j = 60;
	map.mlx = mlx_init();
	map.fd = open(str, O_RDONLY);

	if (map.fd <= 0)
		return (ft_printf("eroor"), 0);
	map.buffer = ft_strdup("");
	map.map_line = ft_strdup("");
	while (1)
	{
		map.buffer = get_next_line(map.fd);
		if (map.buffer == NULL)
			break ;
		if (map.counter == 0)
			map.len = ft_strlen(map.buffer);
		map.counter++;
		map.tmp = map.map_line;
		map.map_line = ft_strjoin(map.tmp, map.buffer);
		free(map.tmp);
		map.tmp = NULL;
		free(map.buffer);
		map.buffer = NULL;
	}
	map.map_info = ft_split(map.map_line, '\n');
	map.len--;
	map.win = mlx_new_window(map.mlx, map.len * 60, map.counter * 60, "test wimdow");
	while (map.map_info[map.y])
	{
		map.x = 0;
		while (map.map_info[map.y][map.x])
		{
			if (map.map_info[map.y][map.x] == '1')
			{
				map.new_img_wall = mlx_xpm_file_to_image(map.mlx, "src/wall.xpm",
					&map.i, &map.j);
					int xx = map.x * 60;
					int yy = map.y * 60;
					mlx_put_image_to_window(map.mlx, map.win,
					map.new_img_wall, xx, yy);
			}
			else if (map.map_info[map.y][map.x] == 'P')
			{
				map.new_img_player = mlx_xpm_file_to_image(map.mlx, "src/player.xpm",
					&map.i, &map.j);
					int xx = map.x * 60;
					int yy = map.y * 60;
					printf("PLAYER IS HERE\n");
				mlx_put_image_to_window(map.mlx, map.win,
					map.new_img_player, xx, yy);
			}
			else if (map.map_info[map.y][map.x] == 'C')
			{
				map.new_img_food = mlx_xpm_file_to_image(map.mlx, "src/food.xpm",
					&map.i, &map.j);
					int xx = map.x * 60;
					int yy = map.y * 60;
					printf("FOOD\n");
				mlx_put_image_to_window(map.mlx, map.win,
					map.new_img_food, xx, yy);
			}
			map.x++;
		}
		map.y++;
	}


	mlx_loop(map.mlx);
	return(0);
}
