/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:01:09 by rgirondo          #+#    #+#             */
/*   Updated: 2019/12/10 17:43:28 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memccpy(void *b, const void *c, int a, size_t len)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;
	size_t			lon;

	lon = 0;
	ptr2 = (unsigned char*)c;
	ptr = (unsigned char*)b;
	if (b == c)
		return (b);
	while (lon < len)
	{
		ptr[lon] = ptr2[lon];
		if (ptr[lon] == (unsigned char)a)
			return (ptr + lon + 1);
		lon++;
	}
	return (NULL);
}
