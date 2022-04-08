/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:15:56 by rgirondo          #+#    #+#             */
/*   Updated: 2020/03/09 19:08:35 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char_flags(t_flags *flags, va_list args)
{
	int		a;
	int		c;

	c = va_arg(args, int);
	a = 0;
	if (flags->flag == '-')
	{
		ft_putchar_fd(c);
		if (1 < flags->width)
			a += ft_width(flags->width - 1, ' ');
	}
	else if (flags->flag == '0')
	{
		if (1 < flags->width)
			a += ft_width(flags->width - 1, '0');
		ft_putchar_fd(c);
	}
	else
	{
		if (1 < flags->width)
			a += ft_width(flags->width - 1, ' ');
		ft_putchar_fd(c);
	}
	return (a + 1);
}

int		ft_width(int a, char b)
{
	int		c;

	c = a;
	while (c > 0)
	{
		write(1, &b, 1);
		c--;
	}
	return (a);
}

int		ft_str_flags(t_flags *flags, va_list args)
{
	int		a;

	a = 0;
	if (flags->flag == '-' || flags->width < 0)
		a = str_if_1(flags, args);
	else if (flags->flag == '0')
		a = str_if_2(flags, args);
	else
		a = str_if_3(flags, args);
	return (a);
}

int		ft_nbr_flags(t_flags *flags, va_list args)
{
	int		a;

	a = 0;
	if (flags->flag == '-' || flags->width < 0)
		a = nbr_if_1(flags, args);
	else if (flags->flag == '0')
		a = nbr_if_2(flags, args);
	else
		a = nbr_if_3(flags, args);
	return (a);
}
