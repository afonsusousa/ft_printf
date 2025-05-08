/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_strs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:48:53 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/08 20:05:37 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

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

int ft_putstr_wrapper(char *str, t_flags *flags)
{
	if(flags->left)
		return (ft_putstr_left(str, flags));
	return (ft_putstr_right(str, flags));
}