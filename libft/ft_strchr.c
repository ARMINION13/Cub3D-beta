/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:05:51 by rgirondo          #+#    #+#             */
/*   Updated: 2020/01/24 19:47:51 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;
	int		a;

	ptr = (char *)str;
	a = 0;
	while (ptr[a] != c && ptr[a] != 0)
		a++;
	if (ptr[a] == c)
		return (ptr + a);
	return (NULL);
}
