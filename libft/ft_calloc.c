/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:05:51 by rgirondo          #+#    #+#             */
/*   Updated: 2019/12/10 16:37:17 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t ni, size_t size)
{
	void	*a;
	size_t	i;

	i = 0;
	if (!(a = malloc(size * ni)))
		return (0);
	while (i < (ni * size))
	{
		((char *)a)[i] = 0;
		i++;
	}
	return (a);
}
