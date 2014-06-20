/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 10:50:28 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/20 16:09:12 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "serveur.h"

void				ft_action_tm(int cs, int t, void (*fn)(), char *rcv)
{
	t_action		new_action;
	long int		tstmp;
	long int		diff;
	struct timeval	tv;
	t_env			*env;

	env = get_env();
	gettimeofday(&tv, NULL);
	tstmp = (1000000 * tv.tv_sec + tv.tv_usec) + ((t / env->time) * 1000000);
	new_action.cs = cs;
	new_action.rcv = ft_strdup(rcv);
	new_action.fn = fn;
	diff = env->fd_socket[cs].last_cmd - (1000000 * tv.tv_sec + tv.tv_usec);
	if (diff > 0)
		tstmp = tstmp + diff;
	new_action.timestamp = tstmp;
	ft_lstpush(&env->actions, ft_lstnew(&new_action, sizeof(new_action)));
}

void				ft_action_special(int cs, int t, void (*fn)(), char *rcv)
{
	t_action		new_action;
	long int		tstmp;
	long int		diff;
	struct timeval	tv;
	t_env			*env;

	env = get_env();
	gettimeofday(&tv, NULL);
	tstmp = (1000000 * tv.tv_sec + tv.tv_usec) + ((t / env->time) * 1000000);
	new_action.cs = -1;
	new_action.rcv = ft_strdup(rcv);
	new_action.fn = fn;
	diff = env->fd_socket[cs].last_cmd - (1000000 * tv.tv_sec + tv.tv_usec);
	if (diff > 0)
		tstmp = tstmp + diff;
	new_action.timestamp = tstmp;
	env->fd_socket[cs].last_cmd = tstmp;
	ft_lstpush(&env->actions, ft_lstnew(&new_action, sizeof(new_action)));
}

void				ft_action_add(int cs, int t, void (*fn)(), char *rcv)
{
	t_action		new_action;
	long int		tstmp;
	long int		diff;
	struct timeval	tv;
	t_env			*env;

	env = get_env();
	gettimeofday(&tv, NULL);
	tstmp = (1000000 * tv.tv_sec + tv.tv_usec) + ((t / env->time) * 1000000);
	new_action.cs = cs;
	new_action.rcv = ft_strdup(rcv);
	new_action.fn = fn;
	diff = env->fd_socket[cs].last_cmd - (1000000 * tv.tv_sec + tv.tv_usec);
	if (diff > 0)
		tstmp = tstmp + diff;
	new_action.timestamp = tstmp;
	env->fd_socket[cs].last_cmd = tstmp;
	ft_lstpush(&env->actions, ft_lstnew(&new_action, sizeof(new_action)));
}
