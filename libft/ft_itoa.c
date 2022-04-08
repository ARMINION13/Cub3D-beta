/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:03:15 by rgirondo          #+#    #+#             */
/*   Updated: 2019/12/10 20:29:19 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int			numlen(int n)
{
	int a;

	a = 0;
	while (n != 0)
	{
		n = n / 10;
		a++;
	}
	return (a + 1);
}

char				*ft_itoa(int n)
{
	char	*str;
	int		a;
	long	m;

	if (n == 0)
		return (ft_strdup("0"));
	m = n;
	a = numlen(m);
	if (!(str = (m < 0) ? (malloc(sizeof(char) * (numlen(m) + 1)))
				: (malloc(sizeof(char) * numlen(m)))))
		return (0);
	a = (n < 0) ? (a) : (a - 1);
	str[a--] = '\0';
	(m < 0) ? (str[0] = '-') : (0);
	m = (m < 0) ? m *= -1 : m;
	while (m != 0)
	{
		str[a--] = (((unsigned int)m % 10) + '0');
		m = m / 10;
	}
	return (str);
}
