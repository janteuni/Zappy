/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 12:10:25 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/13 12:57:47 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_fork(t_env *env, int cs, char *rcv)
{
	t_egg			new_egg;

	(void)rcv;
	ft_reply_in_buff(env, cs, "ok");
	ft_graphic_reply(env, cs, ft_graphic_enw);
	env->count_egg += 1;
	ft_action_tm(cs, 600, ft_treat_egg, ft_itoa(env->count_egg));
	new_egg.num = env->count_egg;
	new_egg.state = GESTATION;
	new_egg.birth = 0;
	new_egg.team = ft_strdup(env->fd_socket[cs].my_team);
	ft_lstpush(&env->eggs, ft_lstnew(&new_egg, sizeof(new_egg)));
}
