/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 11:15:50 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/14 15:44:10 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

void	ft_del_snapshot(void *d, size_t s)
{
	ft_lstdel(&((t_snapshot *)d)->players, ft_del);
	(void)((t_snapshot *)d)->master;
	ft_memdel((void **)&d);
	(void)s;
}

void	ft_del_egg(void *d, size_t s)
{
	ft_memdel((void **)&((t_egg *)d)->team);
	(void)((t_egg *)d)->num;
	(void)((t_egg *)d)->state;
	(void)((t_egg *)d)->father;
	(void)((t_egg *)d)->life;
	ft_memdel((void **)&d);
	(void)s;
}

void	ft_del_action(void *d, size_t s)
{
	ft_memdel((void **)&((t_action *)d)->rcv);
	((t_action *)d)->fn = NULL;
	ft_memdel((void **)&d);
	(void)s;
}

void	ft_del(void *d, size_t s)
{
	ft_memdel((void **)&d);
	(void)s;
}
