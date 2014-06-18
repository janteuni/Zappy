/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 19:52:26 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/18 14:39:33 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_left(t_env *env, int cs, char *rcv)
{
	(void)rcv;
	if (OR(cs) == N)
		OR(cs) = O;
	else if (OR(cs) == O)
		OR(cs) = S;
	else if (OR(cs) == S)
		OR(cs) = E;
	else if (OR(cs) == E)
		OR(cs) = N;
	ft_reply_in_buff(env, cs, "ok");
	printf("ORIENTATION : %d\n", OR(cs));
	ft_graphic_reply(env, cs, ft_graphic_ppo);
}
