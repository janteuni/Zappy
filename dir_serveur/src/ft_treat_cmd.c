/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 14:26:27 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/11 11:52:46 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_cmd(char *rcv, t_env *env, int cs)
{
	printf("%s\n", rcv);
	if (env->fd_socket[cs].type == GRAPHIC)
		ft_graphic_function(env, cs, rcv);
	else if (env->fd_socket[cs].my_team == NULL)
	{
		if (ft_strcmp(rcv, "GRAPHIC") == 0)
			ft_graphic_init(env, cs);
		else if (ft_add_me_team(env, cs, rcv) == OK)
			ft_place_me(env, cs);
	}
	else
	{
		if (ft_function_cmd(env, cs, rcv) == ERR)
			ft_reply_in_buff(env, cs, "Cmd not implemented yet.");
	}
}
