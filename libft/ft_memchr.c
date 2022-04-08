/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:58:09 by rgirondo          #+#    #+#             */
/*   Updated: 2019/12/10 17:43:49 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *str, int chr, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char *)str;
	while (len != 0)
	{
		if (*ptr++ == (unsigned char)chr)
			return (ptr - 1);
		len--;
	}
	return (0);
}
