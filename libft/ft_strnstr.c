/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:15:05 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/18 14:47:40 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lenl;

	i = 0;
	lenl = ft_strlen(little);
	if (little == NULL || *little == '\0')
		return ((char *)big);
	while (big[i] && i + lenl <= len)
	{
		if (ft_strncmp(&big[i], little, lenl) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	printf("%s\n", ft_strnstr("kjfayjufyjago nel pagliaio", "ago", 3));
	//printf("%s", strnstr("kjfayjufyjago nel pagliaio", "ago", 1));
}
*/
