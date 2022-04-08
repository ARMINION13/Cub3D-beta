/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:16:50 by rgirondo          #+#    #+#             */
/*   Updated: 2020/03/09 19:02:52 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		take_precision(char *str, va_list args, t_flags *flags)
{
	int a;

	a = 0;
	if (str[a] == '.' && (str[a + 1] <= '9' && str[a + 1] >= '0'))
	{
		flags->precision = ft_atoi(str + (a + 1));
		a = a + ft_mvnbr(str + a + 1) + 1;
	}
	else if (str[a] == '.' && str[a + 1] == '*')
	{
		flags->precision = va_arg(args, int);
		a = a + 2;
	}
	else if (str[a] == '.' && flags->precision == -1)
	{
		flags->precision = 0;
		a++;
	}
	return (a);
}

int		take_width(char *str, va_list args, t_flags *flags)
{
	int a;

	a = 0;
	if (str[a] <= '9' && str[a] >= '0')
	{
		flags->width = ft_atoi(str + a);
		a = a + ft_mvnbr(str + a);
	}
	else if (str[a] == '*')
	{
		flags->width = va_arg(args, int);
		a++;
	}
	return (a);
}
