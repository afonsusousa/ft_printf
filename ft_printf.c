/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:34:40 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/01 00:15:57 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include "ft_printf.h"

#define UPPERCASE 1
#define LOWERCASE 0

#define U_STR "0123456789ABCDEF"
#define L_STR "0123456789abcdef"

int    ft_putchar(char c)
{
    return (write(1, &c, 1));
}
int    ft_putstr(char *str)
{
    int count;

    count = 0;
    if(!str)
        return (ft_putstr("(nil)"));
    while(*str)
        count += ft_putchar(*str++);
    return (count);
}

int    ft_putnbr(int   n)
{
    int count;
    long int nb;

    nb = n;
    count = 0;
    if(nb < 0)
    {
        nb = -nb;
        count += ft_putchar('-');
    }
    if(nb > 9)
        count += ft_putnbr(nb / 10);
    return (count += ft_putchar(nb % 10 + '0'));
}

int    ft_putunbr(unsigned int n)
{
    int count;

    count = 0;
    if(n > 9)
        count += ft_putunbr(n / 10);
    return (count += ft_putchar(n % 10 + '0'));
}

int    ft_putnbr_hex(unsigned int n, int l_case)
{
    int count;

    count = 0;
    if(n > 15)
        count += (ft_putnbr_hex(n / 16, l_case));
    return (count += ft_putchar((l_case * U_STR[n % 16]) + (!l_case * L_STR[n % 16])));
}

int    ft_putaddress(unsigned long int n)
{
    int count;

    count = 0;
    if(n > 15)
        count += (ft_putaddress(n / 16));
    return (count += ft_putchar((L_STR[n % 16])));
}

int    ft_putspecifier(char c, va_list args)
{
    int count;

    count = 0;
    if(c == 'c')
        count  += ft_putchar(va_arg(args, int));
    if(c == 's')
        count  += ft_putstr(va_arg(args, char *));
    if(c == 'p')
        count  += (ft_putstr("0x")
        + ft_putaddress((long unsigned int) va_arg(args, void *)));
    if(c == 'd')
        count  += ft_putnbr(va_arg(args, int));
    if(c == 'i')
        count  += ft_putnbr(va_arg(args, int));
    if(c == 'u')
        count  += ft_putunbr(va_arg(args, unsigned int));
    if(c == 'x')
        count  += ft_putnbr_hex(va_arg(args, int), LOWERCASE);
    if(c == 'X')
        count  += ft_putnbr_hex(va_arg(args, int), UPPERCASE);
    if(c == '%')
        count  += ft_putchar('%');
    return (count);
}

int ft_printf(const char *format, ...)
{
    int i = 0;
    va_list args;
    va_start(args, format);

    int count;

    count = 0;
    while(1)
    {
        if(format[i] == '%' && format[++i])
            count += ft_putspecifier(format[i++], args);
        if(!format[i])
            break;
        count += ft_putchar(format[i++]);
    }
    va_end(args);
    return (count);
}
//  #include <stdio.h>
// //  int main()
// //  {
// //    int n = INT_MAX;
// //    printf("%d \n", ft_printf(" %d\n %p\n %X\n\n", n, &n, n));
// //    printf("%d \n", printf(" %d\n %p\n %X\n", n, &n, n));
// //  }
