/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:20:31 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/16 15:40:11 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srcsize;
	size_t	dstsize;

	srcsize = 0;
	while (src[srcsize])
		srcsize++;
	dstsize = 0;
	while (dst[dstsize] && dstsize < size)
		dstsize++;
	if (dstsize == size)
		return (size + srcsize);
	i = 0;
	while ((i < (size - dstsize - 1)) && src[i])
	{
		dst[dstsize + i] = src[i];
		i++;
	}
	dst[dstsize + i] = '\0';
	return (dstsize + srcsize);
}
/*
#include <unistd.h>

void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

#include <stdio.h>
int main()
{
	char	*dest;
	int		arg;

	dest[10] = 'a';
	ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 0));
	write(1, "\n", 1);
	write(1, dest, 15);
}
*/