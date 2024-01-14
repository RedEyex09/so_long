/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:26:01 by hel-magh          #+#    #+#             */
/*   Updated: 2023/11/25 10:55:33 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	*s1;

	c1 = (unsigned char) c;
	s1 = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (s1[i] == c1)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
