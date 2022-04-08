/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:27:19 by rgirondo          #+#    #+#             */
/*   Updated: 2019/12/10 17:45:18 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*ptr1;
	const char	*ptr2;
	char		*lastptr;
	const char	*lastptr2;

	ptr1 = str1;
	ptr2 = str2;
	lastptr = str1 + (n - 1);
	lastptr2 = str2 + (n - 1);
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (ptr1 < ptr2)
	{
		while (n--)
			*ptr1++ = *ptr2++;
	}
	else
	{
		while (n--)
			*lastptr-- = *lastptr2--;
	}
	return (str1);
}
