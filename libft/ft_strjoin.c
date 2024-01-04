/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:13:18 by hel-magh          #+#    #+#             */
/*   Updated: 2023/11/25 10:56:44 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*ss;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	ss = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ss == NULL)
		return (NULL);
	while (s1[i])
		ss[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ss[j++] = s2[i++];
	ss[j] = '\0';
	return (ss);
}
