/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_me_team.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 18:40:38 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/13 14:16:37 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int					ft_add_me_team(t_env *env, int cs, char *rcv)
{
	int				i;
	int				max;
	t_player		player;

	i = 0;
	while (i < env->max_team)
	{
		if (ft_strcmp(env->teams[i].name, rcv) == 0)
		{
			max = env->teams[i].max_player - env->teams[i].nb_player;
			if (max > 0)
			{
				env->teams[i].nb_player++;
				player.sock = cs;
				ft_lstadd(&env->teams[i].players,
						ft_lstnew(&player, sizeof(t_player)));
				env->fd_socket[cs].my_team = ft_strdup(rcv);
				return (OK);
			}
			else
				break ;
		}
		i++;
	}
	ft_reply_in_buff(env, cs, "Wrong team or max_player number exceeded");
	return (ERR);
}
