/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 10:50:28 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/11 11:24:07 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "serveur.h"

void				ft_action_add(int cs, int t, void (*fn)(), char *rcv)
{
	t_action		new_action;
	long int		timestamp;
	struct timeval	tv;
	t_env			*env;

	env = get_env();
	gettimeofday(&tv, NULL);
	timestamp = (1000000 * tv.tv_sec + tv.tv_usec) + ((t / env->time) * 1000000);
	new_action.cs = cs;
	new_action.rcv = ft_strdup(rcv);
	new_action.fn = fn;
	new_action.timestamp = timestamp;
	ft_lstpush(&env->actions, ft_lstnew(&new_action, sizeof(new_action)));
}
