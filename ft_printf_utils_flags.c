/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:27:12 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/08 22:33:24 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags     *new_flags()
{
    t_flags *ret;
    
    ret = (t_flags *)malloc(sizeof(t_flags));
    if(!ret)
        return (NULL);
    ret->left = 0;
    ret->zero = 0;
    ret->precision = -1;
    ret->hash = 0;
    ret->space = 0;
    ret->sign = 0;
    ret->width = 0;
    return (ret);
}
int ft_printf_atoi(char **format)
{
    int ret;

    ret = 0;
    if(**format == '.')
        (*format)++;
    while(**format && **format >= '0' && **format <= '9')
        ret = ret * 10 + (*((*format)++) - '0');
    return (ret); 
}

void ft_parse_spec(char **format, t_flags *flags)
{
    while(**format && !is_spec(**format))
    {
        if (**format == '+')
            flags->sign = 1;
        else if (**format == '-')
            flags->left = 1;
        else if (**format == '#')
            flags->hash = 1;
        else if (**format == '0' && !flags->left)
            flags->zero = 1;
        else if (**format == ' ')
            flags->space = 1;
        else if (**format >= '1' && **format <= '9')
        {
            flags->width = ft_printf_atoi(format);
            continue;
        }
        else if(**format == '.')
        {
            flags->precision = ft_printf_atoi(format);
            continue;
        }
        (*format)++;
    }
}
