/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:01:17 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/16 16:14:49 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*src;

	src = (unsigned char *)str;
	while (n > 0)
	{
		if ((unsigned char)c != *src)
		{
			src++;
			n--;
		}
		else
			return (src);
	}
	return (0);
}

/*
#include <stdio.h>
int main()
{
	const char c = 'n';
	char str[] = "bonjourno";
	int n = 2;
	char	*src;

	src = (char *)ft_memchr(str, c, n);
	printf("%s", src);
}
*/