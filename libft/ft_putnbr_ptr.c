/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:32:14 by mruggier          #+#    #+#             */
/*   Updated: 2023/11/02 15:32:39 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_ptr(unsigned long long nbr, char *base, char arg)
{
	char			a;
	unsigned int	len_base;

	len_base = 0;
	while (base[len_base])
		len_base++;
	if (nbr < len_base)
		write(1, &base[nbr], 1);
	else
	{
		ft_putnbr_ptr((nbr / len_base), base, arg);
		a = nbr % len_base;
		write(1, &base[(unsigned char)a], 1);
	}
}

int	ft_put0x(unsigned long long nbr, char *base, char arg)
{
	int	returnsize;

	if (nbr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_putnbr_ptr(nbr, base, arg);
	returnsize = 0;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		returnsize++;
	}
	return (returnsize + 2);
}
