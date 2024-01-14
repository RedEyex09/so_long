/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:10:44 by hel-magh          #+#    #+#             */
/*   Updated: 2023/12/05 19:38:20 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(size_t a)
{
	int	ptr_counter;

	ptr_counter = 0;
	if (a >= 16)
	{
		ptr_counter += ft_ptr_len(a / 16);
		ptr_counter += ft_ptr_len(a % 16);
	}
	else
	{
		if (a <= 9)
			ptr_counter += ft_putchar(a + '0');
		else
			ptr_counter += ft_putchar(a - 10 + 'a');
	}
	return (ptr_counter);
}

int	ft_print_ptr(void *a)
{
	int	ptr_len;

	ptr_len = 0;
	ptr_len += ft_putstr("0x");
	if (a == 0)
		ptr_len += ft_putchar('0');
	else
		ptr_len += ft_ptr_len((size_t) a);
	return (ptr_len);
}
