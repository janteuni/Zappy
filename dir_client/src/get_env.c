/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 16:40:35 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/10 18:53:13 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"

int				init_cmd_tab(t_env *env)
{
	if (!(env->cmds = (int *)malloc(NB_CMDS * sizeof(int))))
		return (ERR);
	ft_bzero(env->cmds, (NB_CMDS * sizeof(int)));
	return (OK);
}

int				init_responces(t_env *env)
{
	if (!(env->replies = (int *)malloc(NB_RESP * sizeof(int))))
		return (ERR);
	ft_bzero(env->replies, (NB_RESP * sizeof(int)));
   return (OK);
}

t_env			*get_env(void)
{
	static t_env	*env = NULL;

	if (!env)
	{
		if (!(env = (t_env *)malloc(sizeof(t_env)))
				|| (init_cmd_tab(env) == ERR)
				|| (init_replies(env) == ERR))
		{
			error("Malloc Failed env");
			return (NULL);
		}
		env->addr = NULL;
		env->port = 0;
		env->dead = 0;
		env->elevating = 0;
		env->level = 1;
		env->team = NULL;
		env->view = NULL;
		env->moves = NULL;
	}
	return (env);
}
