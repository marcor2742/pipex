/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:52:59 by mruggier          #+#    #+#             */
/*   Updated: 2023/12/06 15:08:28 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	check;

	check = 0;
	num = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		check = i;
		i++;
	}
	if ((str[i] >= 48 && str[i] <= 57))
	{
		while ((str[i] >= 48 && str[i] <= 57) && str[i])
			num = (num * 10) + ((char *)str)[i++] - '0';
		if (str[check] == '-')
			num = -num;
		return (num);
	}
	return (0);
}

/*#include <stdlib.h>
#include <stdio.h>
int main()
{
	printf("%d\n", ft_atoi("2356897412"));
	printf("%d", atoi("2356897412")); //overflow
}
*/