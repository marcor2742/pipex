/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:52:49 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/19 17:11:40 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!(unsigned char)c)
	{
		while (str[i])
			i++;
		return ((char *)str + i);
	}
	while (str[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i--;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	printf("%s\n", ft_strrchr("l'ago nel pagliaio", 'a'));
	printf("%s", strrchr("l'ago nel pagliaio", 'a'));
}
*/
