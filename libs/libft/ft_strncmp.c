/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:07:13 by hel-magh          #+#    #+#             */
/*   Updated: 2023/11/25 10:57:15 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((ss1[i] || ss2[i]) && i < n - 1)
	{
		if (ss1[i] == ss2[i])
			i++;
		else
			return (ss1[i] - ss2[i]);
	}
	return (ss1[i] - ss2[i]);
}
