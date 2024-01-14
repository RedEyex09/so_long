/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:12:14 by hel-magh          #+#    #+#             */
/*   Updated: 2023/11/25 10:57:19 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	if (needle[l] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		l = 0;
		while (haystack[i + l] == needle[l] && haystack[i + l] && i + l < len)
		{
			l++;
			if (needle[l] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
