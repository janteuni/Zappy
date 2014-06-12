/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_contains.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 18:41:33 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/12 18:45:43 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int			st_in_list(int nb, t_list *lst)
{
	while (lst)
	{
		if ((int)(*(int *)lst->content) == nb)
			return (YES);
		lst = lst->next;
	}
	return (NO);
}

int					ft_lst_contains(t_list *tocheck, t_list *container)
{
	while (tocheck)
	{
		if (!st_in_list((int)(*(int *)tocheck->content), container))
			return (NO);
		tocheck = tocheck->next;
	}
	return (YES);
}
