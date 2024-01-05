/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:19:10 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/17 12:50:18 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	n;
	size_t	n2;

	n = 0;
	while (s[n])
		n++;
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (0);
	n2 = n;
	n = 0;
	while (n2 > n)
	{
		dup[n] = s[n];
		n++;
	}
	dup[n] = '\0';
	return (dup);
}

/*
#include <stdio.h>
int main()
{
	char	*str;
	char	*tmp = "I malloc so I am.";

	str = ft_strdup(tmp);
	printf("%s", str);
}
*/