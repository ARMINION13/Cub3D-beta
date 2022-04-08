/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_flags2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:15:43 by rgirondo          #+#    #+#             */
/*   Updated: 2020/03/09 19:18:50 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_x_flags(t_flags *flags, va_list args, int base, char c)
{
	int		a;

	a = 0;
	if (flags->flag == '-')
		a = x_if_1(flags, args, base, c);
	else if (flags->flag == '0' && flags->precision < 0)
		a = x_if_2(flags, args, base, c);
	else
		a = x_if_3(flags, args, base, c);
	return (a);
}

int		ft_memadd_flags(t_flags *flags, va_list args)
{
	int		a;

	a = 0;
	if (flags->flag == '-')
		a = memadd_if_1(flags, args);
	else
		a = memadd_if_2(flags, args);
	return (a);
}

int		ft_null_str(char *str)
{
	if (!(str) || !(str[0]))
		return (ft_putstr_fd("(null)", 6));
	return (0);
}

int		ft_100_flags(t_flags *flags)
{
	int		a;

	a = 0;
	if (flags->flag == '-')
	{
		ft_putchar_fd('%');
		if (1 < flags->width)
			a += ft_width(flags->width - 1, ' ');
	}
	else if (flags->flag == '0')
	{
		if (1 < flags->width)
			a += ft_width(flags->width - 1, '0');
		ft_putchar_fd('%');
	}
	else
	{
		if (1 < flags->width)
			a += ft_width(flags->width - 1, ' ');
		ft_putchar_fd('%');
	}
	return (a + 1);
}
