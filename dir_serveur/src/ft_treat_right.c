/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 19:52:52 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/07 17:23:38 by janteuni         ###   ########.fr       */
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
