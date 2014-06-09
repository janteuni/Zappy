/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_broadcast.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 12:42:49 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/09 15:32:51 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void			st_contact_all(char *rcv, int i, t_env *env, int cs)
{
	int				j;

	j = 0;
	while (j < env->max_fd)
	{
		if (env->fd_socket[j].type == CLIENT && cs != j)
		{
			ft_reply_in_buff(env, j, rcv + i);
		}
		j++;
	}
}

void				ft_treat_broadcast(t_env *env, int cs, char *rcv)
{
	int				i;
	char			**split;

	i = 9;
	split = ft_super_split(rcv);
	if (ft_tab_len(split) >= 2)
	{
		while (rcv[i] == ' ')
			i++;
		st_contact_all(rcv, i, env, cs);
		ft_messages_add(env, cs, "ok", 7);
	}
	else
		ft_messages_add(env, cs, "ko", 7);
	ft_free_tab((void ***)&split);
}
