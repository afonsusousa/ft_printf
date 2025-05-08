/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:34:40 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/08 19:00:21 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_putspecifier(char c, va_list args, t_flags *flags)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_address_wrapper(va_arg(args, void *), flags));
	if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_puthex(va_arg(args, int), LOWERCASE));
	if (c == 'X')
		return (ft_puthex(va_arg(args, int), UPPERCASE));
	if (c == '%')
		return (ft_putchar('%'));
	return (ft_putchar(c));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;
	t_flags flags;

	i = 0;
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (format[i] == '%' && format[i + 1])
		{
			format++;
			count += ft_putspecifier(*format, args, &flags);
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
int main()
{
	int  num = 42;
	t_flags test;
	char *spec = "-5d";
	ft_parse_spec(&spec, &test);
	(void) test;
	ft_putchar('[');
	int printed = ft_putnbr_left(num, &test);
	ft_putchar(']');
	printf("%d\n", printed);
	printed = printf("[%-5d]", num);
	printf("%d\n", printed - 2);
}
