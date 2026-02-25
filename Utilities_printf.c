/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguayo- <vaguayo-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:57:33 by vaguayo-          #+#    #+#             */
/*   Updated: 2025/11/03 15:39:24 by vaguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(int arg)
{
	long	n;
	int		count;
	char	c;

	n = arg;
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		count += ft_print_decimal(n / 10);
	c = (n % 10) + '0';
	count += ft_putchar(c);
	return (count);
}

int	ft_print_unsigned(unsigned int arg)
{
	unsigned int	n;
	int				count;
	char			c;

	n = arg;
	count = 0;
	if (n > 9)
		count += ft_print_unsigned(n / 10);
	c = (n % 10) + '0';
	count += ft_putchar(c);
	return (count);
}

int	ft_print_hex(unsigned int arg, char format)
{
	unsigned int	n;
	int				count;
	char			*hex;

	n = arg;
	count = 0;
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_print_hex(n / 16, format);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

static int	ft_recursive_pointer(unsigned long n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_recursive_pointer(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_print_pointer(void *arg)
{
	unsigned long	n;
	int				count;

	count = 0;
	if (!arg)
		return (ft_print_string("(nil)"));
	n = (unsigned long)arg;
	count += ft_print_string("0x");
	count += ft_recursive_pointer(n);
	return (count);
}
