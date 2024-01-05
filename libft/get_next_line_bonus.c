/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:45:12 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/05 17:04:27 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

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

char	*get_next_line(int fd)
{
	static char	*newline[4096];
	char		*line;

	if (fd <= 0 && BUFFER_SIZE <= 0)
		return (0);
	newline[fd] = ft_read(newline[fd], fd);
	if (!newline[fd])
		return (NULL);
	line = ft_correctline(newline[fd]);
	newline[fd] = ft_resto(newline[fd]);
	return (line);
}
