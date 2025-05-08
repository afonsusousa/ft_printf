/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_putunbr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:51:05 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/08 18:41:47 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_unumlen(unsigned int n)
{
	int order;

	order = 0;
	while(n != 0)
	{
		n /= 10;
		order++;
	}
	return (order);
}

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putunbr(n / 10);
	return (count += ft_putchar(n % 10 + '0'));
}

int	ft_putunbr_left(unsigned int n, t_flags *flags)
{
	int count;
	int len;
	int sign;

	count = 0;
	sign = ft_space_sign(n, flags);
	len = ft_unumlen(n);
	if (flags->precision == 0 && !n)
		return (0);
	if(flags->precision > len)
	{
		count += sign + ft_padwith(flags->precision - len, '0');
		len = flags->precision;
	}
	count += ft_putunbr(n);
	count += ft_padwith(flags->width - len, ' ');
	return (count);
}

int ft_putunbr_regular(unsigned int n, t_flags *flags)
{
	int len;
	int count;
	int p_len;

	count = 0;
	len = ft_unumlen(n);
	p_len = len;
	if (flags->precision == 0 && !n)
		return (0);
	if(flags->precision > len)
		p_len = flags->precision;
	if(flags->width > p_len)
	{
		if(flags->sign || flags->space)
			p_len++;
		count += ft_padwith(flags->width - p_len, ' ');
	}
	count += ft_space_sign(n, flags);
	count += ft_padwith(flags->precision - len, '0');
	count += ft_putunbr(n);
	return (count);
}

int	ft_putunbr_zero(unsigned int n, t_flags *flags)
{
	int count;
	int len;

	count = 0;
	len = ft_unumlen(n);
	if(flags->precision != -1)
		ft_putunbr_regular(n, flags);
	if(flags->sign || flags->space)
		len++;
	count += ft_space_sign(n, flags);
	count += ft_padwith(flags->width - len, '0');
	count += ft_putunbr(n);
	return (count);
}