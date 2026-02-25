/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguayo- <vaguayo-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:14:54 by vaguayo-          #+#    #+#             */
/*   Updated: 2025/11/03 15:13:41 by vaguayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(char const *format, ...);

int	ft_dispatcher(char format, va_list args);

int	ft_putchar(char c);
int	ft_print_string(char *str);
int	ft_print_decimal(int num);
int	ft_print_unsigned(unsigned int num);
int	ft_print_hex(unsigned int num, char format);
int	ft_print_pointer(void *ptr);

#endif