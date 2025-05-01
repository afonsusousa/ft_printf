/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:34:40 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/01 20:49:16 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include "ft_printf.h"

int    ft_putspecifier(char c, va_list args)
{
    if(c == 'c')
        return (ft_putchar(va_arg(args, int)));
    if(c == 's')
        return (ft_putstr(va_arg(args, char *)));
    if(c == 'p')
        return (ft_address_wrapper(va_arg(args, void *)));
    if(c == 'd')
        return (ft_putnbr(va_arg(args, int)));
    if(c == 'i')
        return (ft_putnbr(va_arg(args, int)));
    if(c == 'u')
        return (ft_putunbr(va_arg(args, unsigned int)));
    if(c == 'x')
        return (ft_putnbr_hex(va_arg(args, int), LOWERCASE));
    if(c == 'X')
        return (ft_putnbr_hex(va_arg(args, int), UPPERCASE));
    if(c == '%')
        return (ft_putchar('%'));
    return (ft_putchar(c));
}

int ft_printf(const char *format, ...)
{
    int i = 0;
    va_list args;
    va_start(args, format);

    int count;

    count = 0;
    while(format[i])
    {
        if(format[i] == '%' && format[i + 1])
        {
            i++;
            count += ft_putspecifier(format[i], args);
            i++;
        }
        else if(format[i] == '%' && !format[i + 1])
            break;
        else
            count += ft_putchar(format[i++]);
    }
    va_end(args);
    return (count);
}
 #include <stdio.h>
 int main()
 {
   int n = INT_MAX;
   printf("%d\n\n", ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, 
-42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
   printf("%d\n", printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, 
-42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
 }
