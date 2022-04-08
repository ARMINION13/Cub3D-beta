/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:20:18 by rgirondo          #+#    #+#             */
/*   Updated: 2019/12/10 20:27:29 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static char			*finder(char *ptr)
{
	while ((ptr[0] != '-' && ptr[0] != '+')
			&& !(ptr[1] >= '0' && ptr[1] <= '9') && (ptr[0] == ' '
				|| ptr[0] == '\t' || ptr[0] == '\r' || ptr[0] == '\n'
				|| ptr[0] == '\v' || ptr[0] == '\f'))
	{
		if (ptr[0] == ' ' || ptr[0] == '\t' || ptr[0] == '\r'
				|| ptr[0] == '\n' || ptr[0] == '\v' || ptr[0] == '\f')
			ptr++;
	}
	if (ptr[0] == ' ' || ptr[0] == '\t' || ptr[0] == '\r'
			|| ptr[0] == '\n' || ptr[0] == '\v' || ptr[0] == '\f'
			|| ptr[0] == '-' || ptr[0] == '+')
		return (ptr);
	else
		return ("0");
}

static long int		power(long int b, int p)
{
	long int		x;

	x = 1;
	while (p-- != 1)
		x = x * b;
	return (x);
}

static int			len(char *ptr, const char *str, int a)
{
	while (ptr[a + 1] >= '0' && ptr[a + 1] <= '9'
			&& !(str[0] >= '0' && str[0] <= '9'))
		a++;
	while (ptr[a] >= '0' && ptr[a] <= '9' && (str[0] >= '0' && str[0] <= '9'))
		a++;
	return (a);
}

int					ft_atoi(const char *str)
{
	char			*ptr;
	int				a;
	int				b;
	long int		x;

	if (*str == '\0')
		return (0);
	if (!(str[0] >= '0' && str[0] <= '9'))
		ptr = finder((char *)str);
	else
		ptr = (char *)str;
	x = 0;
	b = 0;
	a = 0;
	a = (len(ptr, str, a) + 1);
	if (*ptr == '-' || *ptr == '+' || *ptr == ' ' || *ptr == '\t'
			|| *ptr == '\r' || *ptr == '\n' || *ptr == '\v' || *ptr == '\f')
		b = 1;
	while (a > 1)
		x += (ptr[b++] - '0') * power(10, a--);
	if (*ptr == '-')
		return ((x * -1) / 10);
	return (x / 10);
}
