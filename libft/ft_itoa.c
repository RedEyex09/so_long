/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:19:31 by hel-magh          #+#    #+#             */
/*   Updated: 2023/11/25 16:01:52 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_counter(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	if (nb == 0)
		count++;
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static char	*nb_alloc(int len)
{
	char	*temp;

	temp = malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	temp[0] = '0';
	return (temp);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	long	nb;
	char	*res;

	nb = n;
	len = nb_counter(nb);
	res = nb_alloc(len);
	if (!res)
		return (NULL);
	if (nb < 0)
		nb = -nb;
	i = len - 1;
	while (nb != 0)
	{
		res[i] = (nb % 10) + 48;
		nb = nb / 10;
		i--;
	}
	if (n < 0)
		res[0] = '-';
	res[len] = '\0';
	return (res);
}
