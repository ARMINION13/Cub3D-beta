/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:16:35 by rgirondo          #+#    #+#             */
/*   Updated: 2020/03/09 19:05:55 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnbr_fd(int n)
{
	long int	nbr;
	char		a;

	nbr = n;
	if (nbr < 0)
		nbr = nbr * -1;
	if (nbr > 10)
	{
		ft_putnbr_fd(nbr / 10);
		a = (nbr % 10) + '0';
		ft_putchar_fd(a);
	}
	else
	{
		a = (nbr % 10) + '0';
		ft_putchar_fd(a);
	}
}
