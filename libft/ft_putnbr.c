/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:33:17 by mruggier          #+#    #+#             */
/*   Updated: 2023/11/02 15:33:41 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
		write (1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		c = (n % 10) + '0';
		write(1, &c, 1);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

int	ft_returnsize(int n)
{
	int		returnsize;
	long	nbr;

	ft_putnbr(n);
	returnsize = 0;
	nbr = n;
	if (nbr < 0)
	{
		nbr = -(long)n;
		returnsize = 1;
	}
	if (n == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		returnsize++;
	}
	return (returnsize);
}
