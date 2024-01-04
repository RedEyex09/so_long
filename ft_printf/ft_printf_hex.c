/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:57:04 by hel-magh          #+#    #+#             */
/*   Updated: 2023/12/06 08:52:19 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadicimal(unsigned int a, char format)
{
	int	hex_counter;

	hex_counter = 0;
	if (a >= 16)
	{
		hex_counter += ft_hexadicimal(a / 16, format);
		hex_counter += ft_hexadicimal(a % 16, format);
	}
	else
	{
		if (a <= 9)
			hex_counter += ft_putchar(a + '0');
		else if (format == 'x')
			hex_counter += ft_putchar(a - 10 + 'a');
		else if (format == 'X')
			hex_counter += ft_putchar(a - 10 + 'A');
	}
	return (hex_counter);
}
