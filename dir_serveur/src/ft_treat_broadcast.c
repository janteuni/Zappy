/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_broadcast.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 12:42:49 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/08 12:45:25 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_broadcast(t_env *env, int cs, char *rcv)
{
	(void)rcv;
	printf("broadcast not implemented yet.\n");
	ft_reply_in_buff(env, cs, "broadcast not implemented yet.");
}
