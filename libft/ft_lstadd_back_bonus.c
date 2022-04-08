/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:08:33 by rgirondo          #+#    #+#             */
/*   Updated: 2020/02/11 18:12:47 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *n)
{
	t_list	*tmp;

	if (alst != NULL)
	{
		tmp = *alst;
		if (*alst == NULL)
			*alst = n;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = n;
		}
	}
}
