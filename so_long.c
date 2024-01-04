/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:37:58 by hel-magh          #+#    #+#             */
/*   Updated: 2024/01/04 16:12:10 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*check_map(int fd, char *buffer)
{
	int		i;
	ssize_t	res;
	char	*tmp;
	char	*map_line;

	i = 0;
	res = 1;
	while (res > 0)
	{
		res = read(fd, buffer, BUFFER_MAP);
		if (res == -1)
			return (NULL);
		else if (res == 0)
			break ;
		buffer[res] = '\0';
		tmp = map_line;
		map_line = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (!map_line || ft_strchr(map_line, '\n'))
			break ;
	}
	return (map_line);
}
int ft_chek_walls(int fd)
{
	ssize_t	res;
	int		i;
	int		j;
	int		l;
	char	*line;
	
	res = 0;
	i = 0;
	line = get_next_line(fd);
	j = ft_strlen(line) + 1;
	l = j;
	while ((!*line) && (j = l))
	{
		res++;
		line = get_next_line(fd);
		l = ft_strlen(line) + 1;
	}
	if(ft_strtrim(line, "1") != "\0" || ft_strtrim(line, "1") != "\0" || j!= l )
		return(free(line), line == NULL, 0);
	while(res > 0)
	{
		if(line[res - 1] == '1' && line[res - 1 + j ] == '1')
			res--;
		else
			return(free(line), line == NULL, 0);
	}
	return(1);
}

int ft_map(void)
{
	char	*buffer;
	char	*map_line;
	int		fd;

	fd = open("maps/maps1.ber", O_RDONLY);
	buffer = malloc(((size_t)BUFFER_MAP + 1) * sizeof(char));
	if (!buffer)
		return (free(buffer), buffer = NULL, NULL);
	map_line = check_map(fd, buffer);
	if(!map_line)
		return(free(buffer), buffer = NULL, NULL);
	free(buffer);
	buffer = NULL;
	if (ft_strtrim(map_line, "01CEP") != "\0" || ft_chek_walls(fd) != 1)
		return (free(map_line), map_line = NULL, 0);
	return(1);
}
