/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snapshot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 17:18:22 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/13 11:09:28 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

static void			st_copy_stuff(t_env *env, int i, int stuff[NB_STUFF])
{
	SNAP.stuff[PLAYERS] = stuff[PLAYERS];
	SNAP.stuff[LINEMATE] = stuff[LINEMATE];
	SNAP.stuff[DERAUMERE] = stuff[DERAUMERE];
	SNAP.stuff[SIBUR] = stuff[SIBUR];
	SNAP.stuff[MENDIANE] = stuff[MENDIANE];
	SNAP.stuff[PHIRAS] = stuff[PHIRAS];
	SNAP.stuff[THYSTAME] = stuff[THYSTAME];
}

void				ft_snapshot(t_env *env, int cs, int stuff[NB_STUFF])
{
	int			i;

	i = 0;
	ft_action_add(cs, 300, ft_check_incantation, "elevation");
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type == CLIENT)
		{
			if (POSY(i) == POSY(cs) && POSX(i) == POSX(cs)
					&& env->fd_socket[i].level == env->fd_socket[cs].level)
			{
				SNAP.master = cs;
				SNAP.players = ft_get_players_same_level(env, cs);
				st_copy_stuff(env, i, stuff);
				TOTY(i) = POSY(i);
				TOTX(i) = POSX(i);
				ft_reply_in_buff(env, i, "elevation en cours");
				if (i != cs)
					ft_action_tm(i, 300, ft_check_incantation, "elevation");
			}
		}
		i++;
	}
}
