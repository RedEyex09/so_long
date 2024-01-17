/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:07:28 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/17 21:00:16 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	c_counter(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			c++;
		i++;
	}
	return (c);
}

int	notify(t_map_mlx *map)
{
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
}

int	map_len_validation(t_map_mlx *map)
{
	if (map->len < 43 && map->counter <= 23)
		map->win = mlx_new_window(map->mlx, map->len * 60,
				map->counter * 60, "so_long");
	else
	{
		ft_free(map->map_line);
		ft_free_double(map->map_info, map->counter);
		ft_printf("SIZE OF MAP TOO BIG FOR SCREEN\n");
		exit(0);
	}
	return (0);
}

int	map_read(char *str, t_map_mlx *map)
{
	map->fd = open(str, O_RDONLY);
	if (map->fd <= 0)
		ft_close(map->fd);
	map->map_line = ft_strdup("");
	while (1)
	{
		map->buffer = get_next_line(map->fd);
		if (map->buffer == NULL)
			break ;
		if (map->counter == 0)
			map->len = ft_strlen(map->buffer);
		map->counter++;
		map->tmp = map->map_line;
		map->map_line = ft_strjoin(map->tmp, map->buffer);
		ft_free(map->tmp);
		ft_free(map->buffer);
	}
	ft_free(map->buffer);
	close(map->fd);
	map->len--;
	map->c = c_counter (map->map_line);
	map_len_validation(map);
	map_mlx_read(map, 0);
	return (0);
}

void	mlx_init_map(char *str)
{
	t_map_mlx	map;

	ft_memset(&map, 0, sizeof(map));
	map.str_read = str;
	map.i = 60;
	map.j = 60;
	map.mlx = mlx_init();
	map.new_img_food = mlx_xpm_file_to_image(map.mlx, "src/food.xpm",
			&map.i, &map.j);
	map.new_img_exit = mlx_xpm_file_to_image(map.mlx, "src/exit.xpm",
			&map.i, &map.j);
	map.new_img_player = mlx_xpm_file_to_image(map.mlx, "src/player.xpm",
			&map.i, &map.j);
	map.new_img_wall = mlx_xpm_file_to_image(map.mlx, "src/wall.xpm",
			&map.i, &map.j);
	if (!map.new_img_exit || !map.new_img_food
		|| !map.new_img_player || !map.new_img_wall)
	{
		ft_printf("Poblem in image instialisation\n");
		exit(0);
	}
	map_read(map.str_read, &map);
	mlx_hook(map.win, 2, 0, key_hook, &map);
	mlx_hook(map.win, 17, 0, notify, &map);
	mlx_loop(map.mlx);
}
