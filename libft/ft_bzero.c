/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:06:46 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/12 15:20:50 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		((char *)s)[n - 1] = '\0';
		n--;
	}
}
/*
#include <stdio.h>
int main()
{
	char str[] = "lago nel pagliaio";
	ft_bzero(str, 5);
	printf("%d", str[6]);
}
*/