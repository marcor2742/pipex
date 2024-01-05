/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:00:06 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/19 17:10:06 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == (unsigned char)i)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)i == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	printf("%s\n", ft_strchr("l'ago nel pagliaio", 'r'));
	printf("%s", strchr("l'ago nel pagliaio", 'r'));
}
*/
