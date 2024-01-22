/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:52:32 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/22 18:21:04 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void f(void)
{
	system("leaks so_long");
}


int	main(int argc, char **argv)
{
	int			result;
	atexit(f);
	if (argc == 2)
	{
		result = map_checker(argv[1]);
		if (result == 1)
			mlx_init_map(argv[1]);
		else
			ft_printf("Not a valid map\n");
	}
	return (0);
}
