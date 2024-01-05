/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:33:15 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/17 15:29:49 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*dest;
	char	*src;
	int		i;

	dest = (char *)str1;
	src = (char *)str2;
	if (!str1 && !str2)
		return (0);
	if (dest > src)
	{
		while (n--)
			dest[n] = src[n];
	}
	else
	{
		i = 0;
		while (n--)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (str1);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{//overlapping curl parrot.live
	char d[10] = "copiatore";
	char dest2[10] = "copiatore";
	char *s = "copia";
	int n = 5;
	ft_memmove(d, s, n);
	printf("%s\n", d); 
	memmove(dest2, s, n);
	printf("%s", dest2);
}
*/
