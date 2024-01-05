/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:26:44 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/18 12:44:40 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	char	*st1;
	char	*st2;
	size_t	i;

	i = 0;
	st1 = (char *)str1;
	st2 = (char *)str2;
	while (i < n)
	{
		if (st1[i] != st2[i])
			return ((unsigned char)st1[i] - (unsigned char)st2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%d\n", ft_memcmp("test", "", 4));
	printf("%d", memcmp("test", "", 4));
}
*/
