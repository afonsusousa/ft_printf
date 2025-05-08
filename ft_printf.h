/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:35:12 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/08 20:11:56 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define UPPERCASE 1
# define LOWERCASE 0

# define U_STR "0123456789ABCDEF"
# define L_STR "0123456789abcdef"

typedef struct s_flags
{
	int	left;
	int	zero;
	int	precision;
	int	hash;
	int	space;
	int	sign;
	int	width;
}	t_flags;

/* Core printf functions */
int		ft_printf(const char *format, ...);
int		ft_putspecifier(char c, va_list args, t_flags *flags);

/* Character and string handling */
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnstr(char *str, int n);
int		ft_strlen(char *str);
int		ft_putstr_left(char *str, t_flags *flags);
int		ft_putstr_right(char *str, t_flags *flags);
int		ft_putstr_wrapper(char *str, t_flags *flags);
int		ft_putchar_wrapper(char c, t_flags *flags);

/* Numeric utilities */
int		ft_padwith(int len, char pad);
int		ft_space_sign(int n, t_flags *flags);
int		is_spec(char c);

/* Integer handling */
int		ft_putnbr(int n);
int		ft_putnbr_left(int n, t_flags *flags);
int		ft_putnbr_regular(int n, t_flags *flags);
int		ft_putnbr_zero(int n, t_flags *flags);
int		ft_putnbr_wrapper(int n, t_flags *flags);

/* Unsigned integer handling */
int		ft_putunbr(unsigned int n);
int		ft_putunbr_left(unsigned int n, t_flags *flags);
int		ft_putunbr_regular(unsigned int n, t_flags *flags);
int		ft_putunbr_zero(unsigned int n, t_flags *flags);
int		ft_putunbr_wrapper(int n, t_flags *flags);

/* Hexadecimal handling */
int		ft_puthex(unsigned int n, int l_case);
int		ft_puthex_wrapper(unsigned int n, t_flags *flags, int l_case);

/* Address handling */
int		ft_putaddress(unsigned long int n);
int		ft_address_wrapper(void *p, t_flags *flags);

/* Flag parsing and handling */
t_flags	*new_flags(void);
int		ft_printf_atoi(char **format);
void	ft_parse_spec(char **format, t_flags *flags);

#endif
