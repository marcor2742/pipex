/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:57:39 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/19 18:35:04 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return ((char *)dest);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char dest[50];
	char dest2[50];
	char *src = "";
	int n = 5;
	ft_memcpy(dest, src, n);
	printf("%s\n", dest); 
	memcpy(dest2, src, n);
	printf("%s", dest2);
}
*/
