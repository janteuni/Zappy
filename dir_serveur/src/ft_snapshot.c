/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snapshot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 17:18:22 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/14 14:47:24 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

static void			st_inform_players(t_env *env, int cs)
{
	int			i;

	i = 0;
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type == CLIENT)
		{
			if (POSY(i) == POSY(cs) && POSX(i) == POSX(cs)
					&& env->fd_socket[i].level == env->fd_socket[cs].level)
			{
				TOTY(i) = POSY(i);
				TOTX(i) = POSX(i);
				ft_reply_in_buff(env, i, "elevation en cours");
			}
		}
		i++;
	}
}

void				ft_snapshot(t_env *env, int cs, int stuff[NB_STUFF])
{
	t_snapshot	snapshot;
	char		*str;

	snapshot.master = cs;
	snapshot.pos.x = POSX(cs);
	snapshot.pos.y = POSY(cs);
	snapshot.players = ft_get_players_same_level(env, cs);
	snapshot.stuff[PLAYERS] = stuff[PLAYERS];
	snapshot.stuff[LINEMATE] = stuff[LINEMATE];
	snapshot.stuff[DERAUMERE] = stuff[DERAUMERE];
	snapshot.stuff[SIBUR] = stuff[SIBUR];
	snapshot.stuff[MENDIANE] = stuff[MENDIANE];
	snapshot.stuff[PHIRAS] = stuff[PHIRAS];
	snapshot.stuff[THYSTAME] = stuff[THYSTAME];
	ft_lstpush(&env->elevation, ft_lstnew(&snapshot, sizeof(snapshot)));
	asprintf(&str, "%d %d %d", POSX(cs), POSY(cs), env->fd_socket[cs].level);
	st_inform_players(env, cs);
	ft_action_special(cs, 300, ft_check_incantation, str);
	ft_memdel((void **)&str);
}
