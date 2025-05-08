/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:34:40 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/08 22:13:44 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_putspecifier(char c, va_list args, t_flags *flags)
{
	if (c == 'c')
		return (ft_putchar_wrapper(va_arg(args, int), flags));
	if (c == 's')
		return (ft_putstr_wrapper(va_arg(args, char *), flags));
	if (c == 'p')
		return (ft_address_wrapper(va_arg(args, void *), flags));
	if (c == 'd')
		return (ft_putnbr_wrapper(va_arg(args, int), flags));
	if (c == 'i')
		return (ft_putnbr_wrapper(va_arg(args, int), flags));
	if (c == 'u')
		return (ft_putunbr_wrapper(va_arg(args, unsigned int), flags));
	if (c == 'x')
		return (ft_puthex_wrapper(va_arg(args, int), flags, LOWERCASE));
	if (c == 'X')
		return (ft_puthex_wrapper(va_arg(args, int), flags, UPPERCASE));
	if (c == '%')
		return (ft_putchar('%'));
	return (ft_putchar(c));
}

int	ft_printf(const char *formatt, ...)
{
	int		i;
	int		count;
	va_list	args;
	t_flags *flags;
	char *format = (char *) formatt;

	i = 0;
	count = 0;
	va_start(args, formatt);
	while (*format)
	{
		if (format[i] == '%' && format[i + 1])
		{
			format++;
			flags = new_flags();
			ft_parse_spec(&format, flags);
			count += ft_putspecifier(*format, args, flags);
			free(flags);
			format++;
		}
		else if (format[i] == '%' && !*(format + 1))
			break ;
		else
			count += ft_putchar(*format++);
	}
	va_end(args);
	return (count);
}

#include <stdio.h>
#include <limits.h>
int main()
{
	// t_flags test;
	// char spec[10] = "-5d";
	// ft_parse_spec(&spec, &test);
	// (void) test;
	// ft_putchar('[');
	char *args = "[%-10.5c]";
	char str = 'c';
	int printed = ft_printf(args, str + 256);
	// ft_putchar(']');
	printf("%d\n", printed);
	printed = printf(args, str + 256);
	printf("%d\n", printed);
}
