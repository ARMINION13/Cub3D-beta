/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memadd_if.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:42:10 by rgirondo          #+#    #+#             */
/*   Updated: 2020/07/09 17:12:12 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		memadd_if_1(t_flags *flags, va_list args)
{
	int						a;
	unsigned long int		b;
	char					*str;

	a = 0;
	b = (unsigned long int)va_arg(args, void *);
	str = ft_itoa_v2(b, 16, 'W', -1);
	if (flags->precision != 0)
		a += ft_strlen(str);
	a += write(1, "0x", 2);
	if (a - 2 < flags->precision && flags->precision != 0)
		a += ft_width(flags->precision - (a - 2), '0');
	if (flags->precision != 0)
		ft_putstr_fd(str, 20);
	if (a < flags->width)
		a += ft_width(flags->width - a, ' ');
	if (str)
		free(str);
	return (a);
}

int		memadd_if_2(t_flags *flags, va_list args)
{
	int						a;
	unsigned long int		b;
	char					*str;

	a = 0;
	b = (unsigned long int)va_arg(args, void *);
	str = ft_itoa_v2(b, 16, 'W', -1);
	if (flags->precision != 0)
		a += ft_strlen(str);
	if (a + 2 < flags->width)
		a += ft_width(flags->width - (a + 2), ' ');
	a += write(1, "0x", 2);
	if (ft_strlen(str) < flags->precision)
		a += ft_width(flags->precision - ft_strlen(str), '0');
	if (flags->precision != 0)
		ft_putstr_fd(str, 20);
	if (str)
		free(str);
	return (a);
}
