/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_strs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:48:53 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/08 18:58:27 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(char *str)
{
	char *start;

	start = str;
	if(!str)
		return (0); 
	while(*str)
		str++;
	return (str - start);
}

int ft_putstr(char *str)
{
	int count;

	count = 0;
	while(str && *str)
		count += ft_putchar(*str++);
	return (count);
}
int	ft_putnstr(char *str, int n)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (*str && n--)
	{
		count += ft_putchar(*str++);
	}
	return (count);
}
int	ft_putstr_left(char *str, t_flags *flags)
{
	int len;
	int p_len;
	int count;

	len = ft_strlen(str);
	p_len = len;
	count = 0; 
	if(!str && flags->precision >= 6)
	{
		p_len = 6;
		count += ft_putnstr("(null)", 6);
	}
	if (flags->precision < p_len)
		p_len = flags->precision;
	count += ft_putnstr(str, p_len);
	count += ft_padwith(flags->width - p_len, ' ');
	return (count);
}

int ft_putstr_right(char *str, t_flags *flags)
{
	int len;
	int count;

	len = ft_strlen(str);
	count = 0;
	if(flags->precision < len)
		len = flags->precision;
	if(!str && flags->precision >= 6)
		len = 6;
	count += ft_padwith(flags->width - len, ' ');
	if(!str && flags->precision >= 6)
		count += ft_putnstr("(null)", len);
	count += ft_putnstr(str, len);
	return (count);
}