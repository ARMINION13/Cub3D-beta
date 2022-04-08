/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:00:49 by rgirondo          #+#    #+#             */
/*   Updated: 2019/12/10 17:47:36 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int a;

	if (s == NULL)
		return ;
	a = 0;
	while (s[a] != '\0')
	{
		write(fd, &s[a], sizeof(s[a]));
		a++;
	}
}
