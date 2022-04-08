/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:03:15 by rgirondo          #+#    #+#             */
/*   Updated: 2020/07/01 20:24:16 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char				*ft_itoa_v2(unsigned long n, int base, char asci, int p)
{
	char			*str;
	int				a;

	a = ft_numlen(n, base, p);
	if (!(str = (char*)malloc(sizeof(char) * (a + 1))))
		return (0);
	str[a--] = '\0';
	while (a >= 0)
	{
		if ((n % base) <= 9)
			str[a] = n % base + '0';
		else
			str[a] = n % base + asci;
		n = n / base;
		a--;
	}
	return (str);
}

char				*ft_itoa(long long n, int p)
{
	char			*str;
	int				a;

	a = ft_numlen(n, 10, p);
	if (!(str = (char*)malloc(sizeof(char) * a)))
		return (0);
	str[a--] = '\0';
	(n < 0) ? (str[0] = '-') : (0);
	if (n < 0)
		n *= -1;
	while (a >= 0 && str[a] != '-')
	{
		str[a] = (n % 10) + '0';
		n = n / 10;
		a--;
	}
	return (str);
}
