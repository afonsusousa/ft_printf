/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:35:12 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/01 20:58:09 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(int n);
int ft_putunbr(unsigned int n);
int ft_putnbr_hex(unsigned int n, int l_case);
int ft_putaddress(unsigned long int n);
int ft_address_wrapper(void *p);

#endif
