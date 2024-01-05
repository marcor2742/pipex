/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:34:29 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/20 11:09:32 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_size(long num, int size)
{
	if (num < 0)
	{
		size++;
		num = -num;
	}
	if (num == 0)
		size++;
	while (num > 0)
	{
		num = num / 10;
		size++;
	}
	size--;
	return (size);
}

static char	*ft_num(int size, char *str, long num)
{
	char	a;
	int		size2;
	int		pos;

	pos = 0;
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	else
		pos++;
	size2 = size;
	while (size + pos)
	{
		if (size + 1 == size2 + 1)
			str[size + 1] = '\0';
		a = (num % 10) + 48;
		str[size] = a;
		num = num / 10;
		size--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		size;
	long	num;
	char	*str;

	num = n;
	size = ft_size(num, 0);
	str = (char *)malloc(sizeof(char) * (size + 2));
	if (!str)
		return (NULL);
	ft_num(size, str, num);
	return (str);
}
/*
int main()
{
	printf("%s", ft_itoa(-45648));
}
*/