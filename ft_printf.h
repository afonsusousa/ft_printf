/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:35:12 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/01 20:49:35 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>

#define UPPERCASE 1
#define LOWERCASE 0

#define U_STR "0123456789ABCDEF"
#define L_STR "0123456789abcdef"

int    ft_putchar(char c);
int    ft_putstr(char *str);
int    ft_putnbr(int n);
int    ft_putunbr(unsigned int n);
int    ft_putnbr_hex(unsigned int n, int l_case);
int    ft_putaddress(unsigned long int n);
int    ft_address_wrapper(void *p);
int    ft_putspecifier(char c, va_list args);
int    ft_printf(const char *format, ...);

#endif