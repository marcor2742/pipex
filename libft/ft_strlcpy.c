/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:57:35 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/15 18:34:54 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srcsize;

	srcsize = 0;
	i = 0;
	while (src[srcsize])
		srcsize++;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

/*
#include <stdio.h>
int main()
{
	char dest[50];
	printf("%s\n", dest); 
	printf("%ld", ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0));
}
*/
