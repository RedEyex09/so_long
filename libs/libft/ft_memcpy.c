/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:18:36 by hel-magh          #+#    #+#             */
/*   Updated: 2023/11/25 15:44:15 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_temp;
	unsigned char		*src_temp;
	size_t				i;

	i = 0;
	if (dst == src)
		return (dst);
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	while (i < n)
	{
		dst_temp[i] = src_temp[i];
		i++;
	}
	return (dst);
}
