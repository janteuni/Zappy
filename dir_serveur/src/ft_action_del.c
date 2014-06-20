/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 10:59:43 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/20 17:48:45 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "serveur.h"

void				ft_actions_select(t_env *env)
{
	struct timeval	tv;
	t_list			*act;
	long int		now;

	gettimeofday(&tv, NULL);
	now = 1000000 * tv.tv_sec + tv.tv_usec;
	act = env->actions;
	while (act != NULL)
	{
		if (((t_action *)act->content)->timestamp <= now)
			ft_action_del(env, act);
		act = act->next;
	}
}

void				ft_action_del(t_env *env, t_list *to_del)
{
	int				cs;
	char			*rcv;

	cs = ((t_action *)to_del->content)->cs;
	rcv = ((t_action *)to_del->content)->rcv;
	((t_action *)to_del->content)->fn(env, cs, rcv);
	ft_del_elem(&env->actions, to_del, ft_del_action);
}
