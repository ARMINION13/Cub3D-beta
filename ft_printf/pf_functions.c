/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:20:15 by rgirondo          #+#    #+#             */
/*   Updated: 2020/03/08 19:15:56 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_initialize(t_flags *flags)
{
	flags->flag = ' ';
	flags->width = 0;
	flags->precision = -1;
	flags->type = '\0';
	return (1);
}

int		ft_numlen(long long a, int base, int p)
{
	int			b;
	long long	c;

	c = a;
	b = 0;
	if (a < 0)
		a *= -1;
	if (a == 0)
		a += 1;
	while (a > 0)
	{
		a /= base;
		b++;
	}
	if (b < p || p == 0)
		b = p;
	if (c < 0)
		b += 1;
	return (b);
}
