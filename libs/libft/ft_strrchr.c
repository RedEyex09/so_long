/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:26:00 by hel-magh          #+#    #+#             */
/*   Updated: 2023/11/25 10:57:25 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*res;
	char			c1;

	c1 = (char) c;
	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c1)
			res = ((char *)s + i);
		i++;
	}
	if (s[i] == c1)
		res = ((char *)s + i);
	return (res);
}
