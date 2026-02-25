/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguayo- <vaguayo-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:50:13 by vaguayo-          #+#    #+#             */
/*   Updated: 2025/11/03 15:29:23 by vaguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(char *arg)
{
	char	*str;
	int		i;

	str = arg;
	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_dispatcher(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (format == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_print_decimal(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_calldispatcher(char const *format, va_list args)
{
	int		count;
	int		total;
	size_t	i;

	i = 0;
	total = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count = ft_dispatcher(format[i], args);
			if (count < 0)
				return (-1);
			total += count;
		}
		else
			total += ft_putchar(format[i]);
		i++;
	}
	return (total);
}

int	ft_printf(char const *format, ...)
{
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	count = ft_calldispatcher(format, args);
	va_end(args);
	return (count);
}

/*int	main(void)
{
	int len1, len2;
	char *str = "Hello World";
	int num = 42;
	unsigned int uint = 4294967295;
	void *ptr = &num;

	len1 = ft_printf("String: %s\n", str);
	len2 = printf("String: %s\n", str);
	ft_printf("ft_printf length: %d\n", len1);
	printf("printf length: %d\n", len2);

	len1 = ft_printf("Char: %c, Int: %d, Unsigned: %u\n", 'A', num, uint);
	len2 = printf("Char: %c, Int: %d, Unsigned: %u\n", 'A', num, uint);
	ft_printf("ft_printf length: %d\n", len1);
	printf("printf length: %d\n", len2);

	len1 = ft_printf("Hex: %x, HEX: %X, Pointer: %p\n", num, num, ptr);
	len2 = printf("Hex: %x, HEX: %X, Pointer: %p\n", num, num, ptr);
	ft_printf("ft_printf length: %d\n", len1);
	printf("printf length: %d\n", len2);
	ft_printf("hexadecimal: %x\n", num);
	printf("hexadecimal: %x\n", num);
	ft_printf("hexadecimal: %X\n", num);
	printf("hexadecimal: %X\n", num);
	printf("pointer: %p\n", ptr);
	ft_printf("pointer: %p\n", ptr);
	printf("null pointer: %p\n", NULL);
	ft_printf("null pointer: %p\n", NULL);
	printf("percent sign: %%\n");
	ft_printf("percent sign: %%\n");
	printf("null string: %s\n", NULL);
	ft_printf("null string: %s\n", NULL);
	printf("negative number: %d\n", -num);
	ft_printf("negative number: %d\n", -num);
	printf("zero unsigned: %u\n", 0);
	ft_printf("zero unsigned: %u\n", 0);
	printf("zero hex: %x\n", 0);
	ft_printf("zero hex: %x\n", 0);
	printf("zero pointer: %p\n", 0);
	ft_printf("zero pointer: %p\n", 0);
	len1 = printf("no format: % stop\n", 0);
	len2 = ft_printf("no format: % stop\n", 0);
	printf("printf length: %d\n", len1);
	ft_printf("ft_printf length: %d\n", len2);
	return (0);
}*/
