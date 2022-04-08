/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_if.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:45:50 by rgirondo          #+#    #+#             */
/*   Updated: 2020/07/02 17:30:12 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbr_if_1(t_flags *flags, va_list args)
{
	int				a;
	int				b;
	long long		p;
	char			*str;

	p = flags->precision;
	a = 0;
	b = va_arg(args, long long);
	str = ft_itoa(b, p);
	if (flags->width < 0)
		flags->width *= -1;
	if (flags->precision != 0)
		a += ft_strlen(str);
	if (flags->precision != 0)
		ft_putstr_fd(str, ft_strlen(str));
	if (a < flags->width)
		a += ft_width(flags->width - a, ' ');
	if (str)
		free(str);
	return (a);
}

int		nbr_if_2(t_flags *flags, va_list args)
{
	int				a;
	int				b;
	long long		p;
	char			*str;

	p = flags->precision;
	a = 0;
	b = va_arg(args, long long);
	str = 0;
	if (p == -1 && flags->width != 0)
	{
		p = flags->width;
		if (b < 0)
			p -= 1;
		flags->width = 0;
	}
	str = ft_itoa(b, p);
	a += ft_strlen(str);
	if (a < flags->width)
		a += ft_width(flags->width - a, ' ');
	if (flags->precision != 0)
		ft_putstr_fd(str, ft_strlen(str));
	if (str)
		free(str);
	return (a);
}

int		nbr_if_3(t_flags *flags, va_list args)
{
	int				a;
	int				b;
	long long		p;
	char			*str;

	p = flags->precision;
	a = 0;
	b = va_arg(args, long long);
	str = ft_itoa(b, p);
	a += ft_strlen(str);
	if (a < flags->width)
		a += ft_width(flags->width - a, ' ');
	if (flags->precision != 0)
		ft_putstr_fd(str, ft_strlen(str));
	if (str)
		free(str);
	return (a);
}
