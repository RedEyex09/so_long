/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 09:23:24 by hel-magh          #+#    #+#             */
/*   Updated: 2023/12/07 13:02:14 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(va_list args, const char format)
{
	int	print_j;

	print_j = 0;
	if (format == 's')
		print_j += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		print_j += ft_putnbr(va_arg(args, int));
	else if (format == 'c')
		print_j += ft_putchar(va_arg(args, int));
	else if (format == '%')
		print_j += ft_putchar('%');
	else if (format == 'x' || format == 'X')
		print_j += ft_hexadicimal(va_arg(args, int), format);
	else if (format == 'p')
		print_j += ft_print_ptr(va_arg(args, void *));
	else if (format == 'u')
		print_j += ft_putnbr_unsigned(va_arg(args, int));
	else
		print_j += ft_putchar(format);
	return (print_j);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		print_j;

	if (write(1, "", 0) < 0)
		return (-1);
	print_j = 0;
	va_start (args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			print_j += ft_checker(args, format[i]);
		}
		else
			print_j += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (print_j);
}
