/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:25:33 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/12 15:21:03 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int a)
{
	if (a >= 32 && a < 127)
		return (a);
	else
		return (0);
}
/*
#include <stdio.h>
int main()
{
	int a = '127';
	printf("%d", ft_isprint(a));
}
*/