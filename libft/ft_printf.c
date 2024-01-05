/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:43:41 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/05 17:24:43 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	returnsize;

	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	returnsize = ft_strlen(str);
	write (1, str, returnsize);
	return (returnsize);
}

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_param(const char *format, int i, va_list list)
{
	int	returnsize;

	returnsize = 0;
	if (format[i] == 'c')
		returnsize = ft_putchar(va_arg(list, int));
	else if (format[i] == 's')
		returnsize = ft_putstr(va_arg(list, char *));
	else if (format[i] == 'p')
		returnsize = ft_put0x(va_arg(list, unsigned long long),
				"0123456789abcdef", format[i]);
	else if (format[i] == 'd' || format[i] == 'i')
		returnsize = ft_returnsize(va_arg(list, int));
	else if (format[i] == 'u')
		returnsize = lenbase_print(va_arg(list, unsigned int),
				"0123456789", format[i]);
	else if (format[i] == 'x')
		returnsize = lenbase_print(va_arg(list, unsigned int),
				"0123456789abcdef", format[i]);
	else if (format[i] == 'X')
		returnsize = lenbase_print(va_arg(list, unsigned int),
				"0123456789ABCDEF", format[i]);
	else if (format[i] == '%')
		returnsize = write(1, "%", 1);
	return (returnsize);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		returnsize;

	returnsize = 0;
	i = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			returnsize = returnsize + ft_param(format, i++, list);
		}
		else
		{
			returnsize = returnsize + ft_putchar(format[i++]);
		}
	}
	va_end(list);
	return (returnsize);
}

/*
#include <stdio.h>
int main()
{
	char c = 'A';
	char *s = "Hello, World!";
	int d = 42, i = -123;
	unsigned int u = 99;
	void *p = &d;

// ft_printf("Character: %c\nString: %s\nPointer (hex): 

%p\nDecimal: %d\nInteger: %i\nUnsigned: %u\nHex (lower): 
%x\nHex (upper): %X\nPercent: %%\n", c, s, p, d, i, u, d, d);
// printf("Character: %c\nString: %s\nPointer (hex): 
%p\nDecimal: %d\nInteger: %i\nUnsigned: %u\nHex (lower): 
%x\nHex (upper): %X\nPercent: %%\n", c, s, p, d, i, u, d, d);
// ft_printf("returnsize:%d", ft_printf("%s", "0123"));
// ft_printf("%p", -1);
ft_printf(" returnsize:%u ", ft_printf("%u", 0));
ft_printf(" returnsize:%u ", ft_printf("%u",10));
ft_printf(" returnsize:%u ", ft_printf("%u",100));
ft_printf(" returnsize:%u ", ft_printf("%u",-10));
ft_printf(" returnsize:%u ", ft_printf("%u",-100));
ft_printf(" returnsize:%u ", ft_printf("%u",0));
ft_printf(" returnsize:%u ", ft_printf("%u",-2147483648));
}
 */