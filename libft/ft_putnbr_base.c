/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:32:22 by mruggier          #+#    #+#             */
/*   Updated: 2023/11/02 15:32:36 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long nbr, char *base, char arg, unsigned int l)
{
	char		a;

	if (nbr < l)
		write(1, &base[nbr], 1);
	else
	{
		ft_putnbr_base((nbr / l), base, arg, l);
		a = nbr % l;
		write(1, &base[(unsigned char)a], 1);
	}
}

int	lenbase_print(unsigned long nbr, char *base, char arg)
{
	unsigned int	len_base;
	int				returnsize;

	len_base = 0;
	while (base[len_base])
		len_base++;
	ft_putnbr_base(nbr, base, arg, len_base);
	returnsize = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / len_base;
		returnsize++;
	}
	return (returnsize);
}
