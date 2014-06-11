/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 12:10:25 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/11 15:25:17 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_fork(t_env *env, int cs, char *rcv)
{
	int				i;

	i = 0;
	(void)rcv;
	while (i < env->max_team)
	{
		if (ft_strcmp(env->teams[i].name, env->fd_socket[cs].my_team) == 0)
		{
			env->teams[i].max_player++;
			break ;
		}
		i++;
	}
	ft_reply_in_buff(env, cs, "ok");
}
