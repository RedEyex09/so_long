/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:41:44 by hel-magh          #+#    #+#             */
/*   Updated: 2023/11/26 10:02:09 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;

	if (count > __LONG_MAX__ || size > __LONG_MAX__)
		return (NULL);
	temp = malloc(count * size);
	if (temp == NULL)
		return (NULL);
	ft_bzero(temp, count * size);
	return (temp);
}
