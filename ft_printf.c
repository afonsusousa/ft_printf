/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:34:40 by amagno-r          #+#    #+#             */
/*   Updated: 2025/04/26 00:43:13 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

#define UPPERCASE 1
#define LOWERCASE 0

#define U_STR "0123456789ABCDEF"
#define L_STR "0123456789abcdef"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}
void    ft_putstr(char *str)
{
    if(!str)
        return ;
    while(*str)
        ft_putchar(*str++);
}

void    ft_putnbr(int   n)
{
    long int nb;

    nb = n;
    if(nb < 0)
    {
        ft_putchar('-');
        nb *= -1;
    }
    if(nb <= 9)
        ft_putchar(nb % 10 + '0');
    ft_putnbr(nb / 10);
    ft_putnbr(nb % 10);
}

void    ft_putunbr(unsigned int n)
{
    if(n <= 9)
        ft_putchar(n % 10 + '0');
    ft_putnbr(n / 10);
    ft_putnbr(n % 10);
}

void    ft_putnbr_hex(unsigned int n, int l_case)
{
    if(n <= 16)
        ft_putchar((l_case * U_STR[n % 16]) + (!l_case * L_STR[n % 16]));
    else
    {
        ft_putnbr_hex(n / 16, l_case);
        ft_putnbr_hex(n % 16, l_case);
    }
}

void    ft_putaddress(unsigned long int n)
{
    if(n <= 16)
        ft_putchar(L_STR[n % 16]);
    else
    {
        ft_putaddress(n / 16);
        ft_putaddress(n % 16);
    }
}
void    ft_putspecifier(char c, va_list args)
{
    if(c == 'c')
        ft_putchar(va_arg(args, int));
    if(c == 's')
        ft_putstr(va_arg(args, char *));
    if(c == 'p')
        ft_putaddress((long unsigned int) va_arg(args, void *));
    if(c == 'd')
        ft_putnbr(va_arg(args, int));
    if(c == 'i')
        ft_putnbr(va_arg(args, int));
    if(c == 'u')
        ft_putunbr(va_arg(args, unsigned int));
    if(c == 'x')
        ft_putnbr_hex(va_arg(args, int), LOWERCASE);
    if(c == 'X')
        ft_putnbr_hex(va_arg(args, int), UPPERCASE);
    if(c == '%')
        ft_putchar('%');
}

void ft_printf(char *format, ...)
{
    int i = 0;
    va_list args;
    va_start(args, 0);
    while(1)
    {
        if(format[i] == '%' && format[++i])
            ft_putspecifier(format[i++], args);
        if(!format[i])
            break;
        ft_putchar(format[i++]);
    }
    va_end(args);
}
#include <stdio.h>
int main()
{
    int n = INT_MIN;
    printf(" %p\n ", n);
    ft_printf(" %p\n ", n);
}