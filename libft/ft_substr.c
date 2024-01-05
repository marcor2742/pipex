/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:01:16 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/17 15:36:09 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	lensrc;

	i = 0;
	lensrc = ft_strlen(s);
	if (start + len > lensrc && start < lensrc)
		len = lensrc - start;
	if (start >= lensrc)
		len = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	while (s[i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
#include <stdio.h>
int	main()
{
	printf("%s", ft_substr("123456789215", 3, 6));
}
*/