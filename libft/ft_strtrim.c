/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:21:25 by rgirondo          #+#    #+#             */
/*   Updated: 2019/12/10 20:33:17 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	comp(char const s1, char const *set)
{
	char	*str;

	str = (char*)set;
	while (*str != '\0')
	{
		if (*str == s1)
			return (1);
		str++;
	}
	return (0);
}

static int	len(char *ptr)
{
	int		i;

	i = 0;
	while (ptr[i] != '\0')
		i++;
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*ult;
	int		a;
	int		b;

	if (s1 == NULL || set == NULL)
		return (NULL);
	b = 0;
	a = len((char*)s1) - 1;
	while (comp(s1[b], set) != 0 && s1[b])
		b++;
	if (b == len((char*)s1))
		return (ft_strdup(""));
	while (comp(s1[a], set) != 0 && s1[a] && a >= 0)
		a--;
	if (!(ult = malloc(sizeof(char) * (a - b + 2))))
		return (NULL);
	ult[a - b + 1] = '\0';
	while (a - b >= 0)
	{
		ult[a - b] = '\0';
		ult[a - b] = s1[a];
		a--;
	}
	return (ult);
}
