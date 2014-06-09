/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 11:15:50 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/09 18:11:17 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

void	ft_del_mess(void *d, size_t s)
{
	ft_memdel((void **)&((t_message *)d)->msg);
	ft_memdel((void **)&d);
	(void)s;
}

void	ft_del(void *d, size_t s)
{
	ft_memdel((void **)&d);
	(void)s;
}
