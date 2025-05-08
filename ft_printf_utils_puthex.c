/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_puthex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:50:13 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/07 22:09:52 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_hexlen(unsigned int n)
{
	int order;

	order = 0;	
	while(n != 0)
	{
		n /= 16;
		order++;
	}
	return (order);
}

int	ft_puthex(unsigned int n, int l_case)
{
	int	count;

	count = 0;
	if (n > 15)
		count += (ft_puthex(n / 16, l_case));
	if (l_case)
		count += ft_putchar(L_STR[n % 16]);
	else
		count += ft_putchar(U_STR[n % 16]);
	return (count);
}

int	ft_puthex_left(unsigned int n, t_flags *flags, int l_case)
{
	int count;
	int len;

	count = 0;
	len = ft_hexlen(n);
	if (flags->precision == 0 && !n)
		return (0);
    if(flags->hash)
    {
        len += 2;
        count += ft_putchar('0') 
                + ft_putchar((l_case * 'x') + (!l_case * 'X'));
    }
	if(flags->precision > len)
	{
		count += ft_padwith(flags->precision - len, '0');
		len = flags->precision;
	}
	count += ft_puthex(n, l_case);
	if(flags->width > len)
		count += ft_padwith(flags->width - len, ' ');
	return (count);
}

int ft_puthex_regular(int n, t_flags *flags, int l_case)
{
	int len;
	int count;
	int p_len;

	count = 0;
	len = ft_hexlen(n);
	p_len = len;
	if (flags->precision == 0 && !n)
		return (0);
	if(flags->precision > len)
		p_len = flags->precision;
	if(flags->width > p_len)
		count += ft_padwith(flags->width - p_len - (flags->hash * 2), ' ');
    if (flags->hash)
    {
        count += ft_putchar('0') + ft_putchar((l_case * 'x') + (!l_case * 'X'));
    }
	if (flags->precision > len)
		count += ft_padwith(flags->precision - len, '0');
	count += ft_puthex(n, l_case);
	return (count);
}

int	ft_puthex_zero(unsigned int n, t_flags *flags, int l_case)
{
	int count;
	int len;

	count = 0;
	len = ft_hexlen(n);
	if(flags->precision != -1)
		ft_puthex_regular(n, flags, l_case);
	if(flags->sign || flags->space )
		len++;
	count += ft_padwith(flags->width - len, '0');
	count += ft_putnbr(n);
	return (count);
}