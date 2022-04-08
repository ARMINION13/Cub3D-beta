/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:13:07 by rgirondo          #+#    #+#             */
/*   Updated: 2019/12/13 19:22:24 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;

	ptr2 = (unsigned char *)str;
	ptr = (unsigned char *)str;
	while (*ptr != '\0')
	{
		ptr++;
		if (*ptr == c)
			ptr2 = ptr;
	}
	if (*ptr2 == c)
		return ((char *)ptr2);
	return (NULL);
}
