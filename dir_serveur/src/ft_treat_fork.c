/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 12:10:25 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/11 11:36:35 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_fork(t_env *env, int cs, char *rcv)
{
	(void)rcv;
	ft_reply_in_buff(env, cs, "ok");
}
