/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:15:29 by rgirondo          #+#    #+#             */
/*   Updated: 2019/12/10 17:46:56 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;
	char		a;

	nbr = n;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		write(fd, "-", 1);
	}
	if (nbr > 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		a = (nbr % 10) + '0';
		write(fd, &a, 1);
	}
	else
	{
		a = (nbr % 10) + '0';
		write(fd, &a, 1);
	}
}
