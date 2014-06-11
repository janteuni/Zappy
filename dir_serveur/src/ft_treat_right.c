/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 15:36:20 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/11 11:37:41 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_right(t_env *env, int cs, char *rcv)
{
	(void)rcv;
	if (OR(cs) == N)
		OR(cs) = E;
	else if (OR(cs) == E)
		OR(cs) = S;
	else if (OR(cs) == S)
		OR(cs) = O;
	else if (OR(cs) == O)
		OR(cs) = N;
	ft_reply_in_buff(env, cs, "ok");
}
