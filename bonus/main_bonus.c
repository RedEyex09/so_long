/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:52:32 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/19 18:35:48 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	int			result;

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
