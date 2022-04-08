/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:33:08 by rgirondo          #+#    #+#             */
/*   Updated: 2019/12/12 21:18:40 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		a;
	size_t		b;

	a = 0;
	b = 0;
	if (!src)
		return (0);
	while (src[a] != '\0')
		a++;
	if (!size)
		return (a);
	while (src[b] != '\0' && b < (size - 1))
	{
		dest[b] = src[b];
		b++;
	}
	if (size != 0)
		dest[b] = '\0';
	return (a);
}
