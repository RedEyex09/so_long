/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:31:42 by hel-magh          #+#    #+#             */
/*   Updated: 2023/11/25 10:56:22 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_vars(size_t *i, int *j, int *w_count)
{
	*i = 0;
	*j = 0;
	*w_count = -1;
}

static int	ft_counter(char const *str, char c)
{
	int	i;
	int	j;
	int	w_count;

	i = 0;
	j = 0;
	w_count = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] != c && j == 0)
		{
			j = 1;
			w_count++;
		}
		else if (str[i] == c)
			j = 0;
		i++;
	}
	return (w_count);
}

static char	*ft_word(char const *str, int s, int d)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc((d - s + 1), sizeof(char));
	if (!word)
		return (NULL);
	while (s < d)
	{
		word[i] = str[s];
		i++;
		s++;
	}
	return (word);
}

static void	*ft_free(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		w_count;
	size_t	i;
	int		j;

	ft_vars(&i, &j, &w_count);
	res = ft_calloc((ft_counter(s, c) + 1), sizeof(char *));
	if (!s || !res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && w_count < 0)
			w_count = i;
		else if ((s[i] == c || i == ft_strlen(s)) && w_count >= 0)
		{
			res[j] = ft_word(s, w_count, i);
			if (!res[j])
				return (ft_free(res, j));
			w_count = -1;
			j++;
		}
		i++;
	}
	return (res);
}
