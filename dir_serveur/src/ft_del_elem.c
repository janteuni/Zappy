/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 12:37:19 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/11 10:57:07 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void			ft_del_elem(t_list **begin, t_list *to_del, void (*del)(void *, size_t))
{
	t_list		*prev;
	t_list		*tmp;

	prev = NULL;
	tmp = *begin;
	while (tmp)
	{
		if (tmp == to_del)
		{
			if (prev)
				prev->next = tmp->next;
			else
				*begin = tmp->next;
			ft_lstdelone(&tmp, del);
			break ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
