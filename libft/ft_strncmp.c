/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:01:36 by rgirondo          #+#    #+#             */
/*   Updated: 2019/12/13 19:24:28 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned	int	a;

	a = 0;
	if (n == 0)
		return (0);
	while (*s1 == *s2 && (n - 1) > a && *s2)
	{
		s1++;
		s2++;
		a++;
	}
	if (*s1 != *s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}
