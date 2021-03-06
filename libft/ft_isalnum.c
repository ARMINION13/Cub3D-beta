/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:52:38 by rgirondo          #+#    #+#             */
/*   Updated: 2019/12/10 16:49:48 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int		ft_isalnum(int a)
{
	if ((64 < a && a < 91) || (96 < a && a < 123) || (47 < a && a < 58))
		return (1);
	else
		return (0);
}
