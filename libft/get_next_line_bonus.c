/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:45:12 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/16 13:34:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "../pipex.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strcmp2(const char *str1, const char *str2)
{
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)(*str1) - (unsigned char)(*str2));
}

char	*ft_read(char *newline, int fd)
{
	char	*buf;
	int		rd;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	rd = 1;
	while (rd > 0 && ft_strchr_line(newline, '\n') == 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free(newline);
			free(buf);
			return (0);
		}
		buf[rd] = '\0';
		newline = ft_strjoin_line(newline, buf);
	}
	free(buf);
	return (newline);
}

char	*get_next_line(int fd, t_data *data)
{
	static char	*newline[4096];
	char		*line;

	if (fd <= 0 && BUFFER_SIZE <= 0)
		return (0);
	newline[fd] = ft_read(newline[fd], fd);
	if (!newline[fd])
		return (NULL);
	line = ft_correctline(newline[fd]);
	newline[fd] = ft_resto(newline[fd], data);
	return (line);
}
