/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snapshot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 17:18:22 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/12 18:39:26 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

void				ft_snapshot(t_env *env, int cs, int stuff[NB_STUFF])
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
				SNAP.players = ft_get_players_same_level(env, cs);
				SNAP.stuff = stuff;
				TOTY(i) = POSY(i);
				TOTX(i) = POSX(i);
				ft_reply_in_buff(env, i, "elevation en cours");
				ft_action_add(i, 300, ft_check_incantation, "elevation");
			}
		}
		i++;
	}
}
