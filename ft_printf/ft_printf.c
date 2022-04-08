/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:03:12 by rgirondo          #+#    #+#             */
/*   Updated: 2020/07/09 17:13:22 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *str, ...)
{
	int			a;
	va_list		args;
	t_flags		*flags;
	int			b;

	b = 0;
	a = 0;
	va_start(args, str);
	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (-1);
	while (str[a])
	{
		if (str[a] == '%')
		{
			ft_initialize(flags);
			a = ft_flags((char *)str, args, a + 1, flags);
			b += ft_types(flags->type, flags, args);
		}
		else
			b += ft_putchar_fd(str[a]);
		a++;
	}
	free(flags);
	va_end(args);
	return (b);
}

int			ft_flags(char *str, va_list args, int a, t_flags *flags)
{
	int b;

	b = 0;
	while (flags->type == '\0' && b++ < 10)
	{
		if ((str[a] == '-' || str[a] == '0'))
		{
			if (flags->flag != '-')
				flags->flag = str[a];
			a++;
		}
		else if ((str[a] <= '9' && str[a] >= '0') || str[a] == '*')
			a += take_width(str + a, args, flags);
		else if (str[a] == '.')
			a += take_precision(str + a, args, flags);
		else if (ft_strchr("cspdiuxX%", str[a]) && str[a] != '\0')
			flags->type = str[a++];
	}
	return (a - 1);
}

int			ft_types(char c, t_flags *flags, va_list args)
{
	int a;

	a = 0;
	if (c == 'c')
		a += ft_char_flags(flags, args);
	if (c == 's')
		a += ft_str_flags(flags, args);
	if (c == 'd' || c == 'i')
		a += ft_nbr_flags(flags, args);
	if (c == 'u')
		a += ft_x_flags(flags, args, 10, 0);
	if (c == 'X')
		a += ft_x_flags(flags, args, 16, 55);
	if (c == 'x')
		a += ft_x_flags(flags, args, 16, 87);
	if (c == 'p')
		a += ft_memadd_flags(flags, args);
	if (c == '%')
		a += ft_100_flags(flags);
	return (a);
}

int			ft_mvnbr(char *str)
{
	int a;

	a = 0;
	while (str[a] <= '9' && str[a] >= '0')
		a++;
	return (a);
}
