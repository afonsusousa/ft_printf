/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_address.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:22:15 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/08 21:41:57 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(unsigned long int n)
{
	int	count;

	count = 0;
	if (n > 15)
		count += (ft_putaddress(n / 16));
	return (count += ft_putchar((L_STR[n % 16])));
}

int	ft_address_wrapper(void *p, t_flags *flags)
{
	int count;

	count = 0;
	if (!p && flags->left)
	{
		count += ft_putstr("(nil)") + ft_padwith(flags->width - 5, ' ');
	}
	else if (!p)
	{
		count += ft_padwith(flags->width - 5, ' ') + ft_putstr("(nil)");
	}
	if(flags->left && p)
	{
		count += ft_putstr("0x") + ft_putaddress((unsigned long int) p);
		count += ft_padwith(flags->width - 14, ' ');
	}
	else
	{
		count += ft_padwith(flags->width - 14, ' ');
		count += ft_putstr("0x") + ft_putaddress((unsigned long int) p);
	}
	return (count);
}
