/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:35:47 by mruggier          #+#    #+#             */
/*   Updated: 2023/12/14 15:19:26 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int	ft_clines(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_putword(char *nword, char const *s, int i, int cchar)
{
	int	j;

	j = 0;
	while (cchar > 0)
	{
		nword[j] = s[i - cchar];
		j++;
		cchar--;
	}
	nword[j] = '\0';
	return (nword);
}

static char	**ft_enter(char const *s, char c, char **s2, int clines)
{
	int	i;
	int	nword;
	int	cchar;

	i = 0;
	nword = 0;
	cchar = 0;
	while (nword < clines)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			cchar++;
		}
		s2[nword] = (char *)malloc(sizeof(char) * (cchar + 1));
		if (!s2)
			return (free_array(s2, nword));
		ft_putword(s2[nword], s, i, cchar);
		cchar = 0;
		nword++;
	}
	s2[nword] = (void *)0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	clines;

	if (!s)
		return (0);
	clines = ft_clines(s, c);
	s2 = (char **)malloc(sizeof(char *) * (clines + 1));
	if (!s2)
		return (0);
	s2 = ft_enter(s, c, s2, clines);
	return (s2);
}
