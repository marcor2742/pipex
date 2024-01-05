/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:18:56 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/19 18:42:36 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	size_t	n;

	if (nmemb > 0 && (size > 2147483647 / nmemb))
		return (NULL);
	n = nmemb * size;
	str = (char *)malloc(sizeof(char) * n);
	if (!str)
		return (0);
	else
	{
		while (n > 0)
		{
			((char *)str)[n - 1] = '\0';
			n--;
		}
	}
	return (str);
}
/*
#include <stdio.h>
int	main()
{
	size_t nmemb = 5;
	size_t size = 5;
	ft_calloc(nmemb, size);
	printf("%s", (char *)calloc(nmemb, size));
}
*/
