/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:00:18 by hel-magh          #+#    #+#             */
/*   Updated: 2023/12/04 17:49:48 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	r;
	int	counter;

	counter = 0;
	r = n;
	if (n == -2147483648)
	{
		counter += ft_putchar('-');
		counter += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		counter += ft_putchar('-');
		n = -n;
	}
	if (n < 10)
		counter += ft_putchar((n + '0'));
	else
	{
		counter += ft_putnbr(n / 10);
		counter += ft_putnbr(n % 10);
	}
	return (counter);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	r;
	int				counter;

	counter = 0;
	r = n;
	if (n < 10)
		counter += ft_putchar((n + '0'));
	else
	{
		counter += ft_putnbr_unsigned(n / 10);
		counter += ft_putnbr_unsigned(n % 10);
	}
	return (counter);
}
