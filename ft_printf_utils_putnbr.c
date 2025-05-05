/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_putnbr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:20:59 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/05 19:21:40 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int			count;
	long int	nb;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		nb = -nb;
		count += ft_putchar('-');
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	return (count += ft_putchar(nb % 10 + '0'));
}

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putunbr(n / 10);
	return (count += ft_putchar(n % 10 + '0'));
}

int	ft_putnbr_hex(unsigned int n, int l_case)
{
	int	count;

	count = 0;
	if (n > 15)
		count += (ft_putnbr_hex(n / 16, l_case));
	return (count += ft_putchar((l_case * U_STR[n % 16]) 
        + (!l_case * L_STR[n % 16])));
}