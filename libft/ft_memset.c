/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:59:42 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/12 15:22:12 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*s;

	s = str;
	i = 0;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (str);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char s[] = "suca efg defgh";
	ft_memset(s, '#', 4);
	printf("%s\n", s);
	memset(s, '#', 4);
	printf("%s", s);
	((char*)(s))[i] = c
}
*/
