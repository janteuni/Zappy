/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_avance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 19:48:16 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/07 17:22:39 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_avance(t_env *env, int cs, char *rcv)
{
	t_pos			new_pos;

	(void)rcv;
	new_pos.x = POSX(cs);
	new_pos.y = POSY(cs);
	new_pos.o = OR(cs);
	if (OR(cs) == N)
		new_pos.y = new_pos.y == 0 ? HEIGHT - 1 : new_pos.y - 1;
	else if (OR(cs) == S)
		new_pos.y = new_pos.y == HEIGHT - 1 ? 0 : new_pos.y + 1;
	else if (OR(cs) == O)
		new_pos.x = new_pos.x == 0 ? WIDTH - 1 : new_pos.x - 1;
	else if (OR(cs) == E)
		new_pos.x = new_pos.x == WIDTH - 1 ? 0 : new_pos.x + 1;
	POSX(cs) = new_pos.x;
	POSY(cs) = new_pos.y;
	printf("new pos: %d %d\n", new_pos.x, new_pos.y);
	ft_reply_in_buff(env, cs, "ok");
}
