/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:55:20 by hel-magh          #+#    #+#             */
/*   Updated: 2023/11/26 08:30:44 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	if (dst == NULL && src == NULL)
		return (NULL);
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (temp_dst > temp_src)
	{
		while (len > 0)
		{
			len--;
			temp_dst[len] = temp_src[len];
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
