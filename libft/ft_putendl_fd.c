/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:11:15 by rgirondo          #+#    #+#             */
/*   Updated: 2019/12/10 17:46:30 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int a;

	if (s == NULL)
		return ;
	a = 0;
	while (s[a])
	{
		write(fd, &s[a], sizeof(s[a]));
		a++;
	}
	write(fd, "\n", 1);
}
