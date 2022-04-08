/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_if.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:50:09 by rgirondo          #+#    #+#             */
/*   Updated: 2020/07/09 17:12:49 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		x_if_1(t_flags *flags, va_list args, int base, char c)
{
	int				a;
	int				p;
	unsigned int	b;
	char			*str;

	p = flags->precision;
	a = 0;
	b = va_arg(args, unsigned int);
	str = ft_itoa_v2(b, base, c, p);
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

int		x_if_2(t_flags *flags, va_list args, int base, char c)
{
	int				a;
	int				p;
	unsigned int	b;
	char			*str;

	p = flags->precision;
	a = 0;
	b = va_arg(args, unsigned int);
	str = ft_itoa_v2(b, base, c, p);
	if (flags->precision != 0)
		a += ft_strlen(str);
	if (a < flags->width)
		a += ft_width(flags->width - a, '0');
	if (flags->precision != 0)
		ft_putstr_fd(str, ft_strlen(str));
	if (str)
		free(str);
	return (a);
}

int		x_if_3(t_flags *flags, va_list args, int base, char c)
{
	int				a;
	int				p;
	unsigned int	b;
	char			*str;

	p = flags->precision;
	a = 0;
	b = va_arg(args, unsigned int);
	str = ft_itoa_v2(b, base, c, p);
	if (flags->precision != 0)
		a += ft_strlen(str);
	if (a < flags->width)
		a += ft_width(flags->width - a, ' ');
	if (flags->precision != 0)
		ft_putstr_fd(str, ft_strlen(str));
	if (str)
		free(str);
	return (a);
}
