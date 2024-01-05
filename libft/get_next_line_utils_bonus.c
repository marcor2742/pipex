/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:46:33 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/05 17:09:05 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_line(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen_line(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_line(char *newline, char *buf)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!newline)
	{
		newline = (char *)malloc(1 * sizeof(char));
		if (!newline || !buf)
			return (NULL);
		newline[0] = '\0';
	}
	res = malloc(sizeof(char) * (ft_strlen_line(newline)
				+ ft_strlen_line(buf) + 1));
	if (!res)
		return (0);
	i = -1;
	j = 0;
	if (newline)
		while (newline[++i] != '\0')
			res[i] = newline[i];
	while (buf[j] != '\0')
		res[i++] = buf[j++];
	res[ft_strlen_line(newline) + ft_strlen_line(buf)] = '\0';
	free(newline);
	return (res);
}

char	*ft_correctline(char *newline)
{
	char	*line;
	int		i;

	i = 0;
	if (!newline[i])
		return (NULL);
	while (newline[i] && newline[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (newline[i] && newline[i] != '\n')
	{
		line[i] = newline[i];
		i++;
	}
	if (newline[i] == '\n')
	{
		line[i] = newline[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_resto(char *newline)
{
	int		i;
	int		j;
	char	*returnline;

	i = 0;
	while (newline[i] && newline[i] != '\n')
		i++;
	if (!newline[i])
	{
		free(newline);
		return (NULL);
	}
	returnline = malloc(sizeof(char) * (ft_strlen_line(newline) - i + 1));
	if (!returnline)
		return (0);
	i++;
	j = 0;
	while (newline[i])
		returnline[j++] = newline[i++];
	returnline[j] = '\0';
	free(newline);
	return (returnline);
}
