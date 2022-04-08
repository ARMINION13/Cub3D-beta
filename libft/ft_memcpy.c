/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:15:06 by rgirondo          #+#    #+#             */
/*   Updated: 2019/12/10 17:44:49 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *b, const void *c, size_t len)
{
	char		*ptr;
	const char	*ptr2;

	ptr2 = c;
	ptr = b;
	if (b == 0 && c == 0)
		return (0);
	while (len != 0)
	{
		*(ptr++) = *(ptr2++);
		len--;
	}
	return (b);
}
