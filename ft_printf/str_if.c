/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_if.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:47:36 by rgirondo          #+#    #+#             */
/*   Updated: 2020/07/02 17:39:16 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		str_if_1(t_flags *flags, va_list args)
{
	int		a;
	char	*str;

	if (!(str = va_arg(args, char*)))
		if (!(str = ft_strdup("(null)")))
			return (0);
	a = 0;
	if (flags->precision < 0 || flags->precision > ft_strlen(str))
		flags->precision = ft_strlen(str);
	if (flags->width < 0)
		flags->width *= -1;
	a += ft_putstr_fd(str, flags->precision);
	if (a < flags->width)
		a += ft_width(flags->width - a, ' ');
	if (ft_strncmp(str, ("(null)"), ft_strlen(str) + 1) == 0)
		free(str);
	return (a);
}

int		str_if_2(t_flags *flags, va_list args)
{
	int		a;
	char	*str;

	if (!(str = va_arg(args, char*)))
		if (!(str = ft_strdup("(null)")))
			return (0);
	a = 0;
	if (flags->precision < 0 || flags->precision > ft_strlen(str))
		flags->precision = ft_strlen(str);
	a += ft_strlen2(str, flags->precision);
	if (a < flags->width)
		a += ft_width(flags->width - a, '0');
	ft_putstr_fd(str, flags->precision);
	if (ft_strncmp(str, ("(null)"), ft_strlen(str) + 1) == 0)
		free(str);
	return (a);
}

int		str_if_3(t_flags *flags, va_list args)
{
	int		a;
	char	*str;

	if (!(str = va_arg(args, char*)))
		if (!(str = ft_strdup("(null)")))
			return (0);
	a = 0;
	if (flags->precision < 0 || flags->precision > ft_strlen(str))
		flags->precision = ft_strlen(str);
	a += ft_strlen2(str, flags->precision);
	if (a < flags->width)
		a += ft_width(flags->width - a, ' ');
	ft_putstr_fd(str, flags->precision);
	if (ft_strncmp(str, ("(null)"), ft_strlen(str) + 1) == 0)
		free(str);
	return (a);
}
