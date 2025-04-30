/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:35:12 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/01 00:01:06 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>

int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(int n);
int ft_putunbr(unsigned int n);
int ft_putnbr_hex(unsigned int n, int l_case);
int ft_putaddress(unsigned long int n);
int ft_putspecifier(char c, va_list args);
int ft_printf(const char *format, ...);

#endif