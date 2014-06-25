/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 16:40:35 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/25 17:50:28 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"

static int			init_cmd_tab(t_env *env)
{
	if (!(env->cmds = (char **)malloc((NB_CMDS + 1) * sizeof(char *))))
		return (ERR);
	env->cmds[NB_CMDS] = NULL;
	env->cmds[AVANCE] = ft_strdup("avance\n");
	env->cmds[DROITE] = ft_strdup("droite\n");
	env->cmds[GAUCHE] = ft_strdup("gauche\n");
	env->cmds[VOIR] = ft_strdup("voir\n");
	env->cmds[INVENT] = ft_strdup("inventaire\n");
	env->cmds[PREND] = ft_strdup("prend ");
	env->cmds[POSE] = ft_strdup("pose ");
	env->cmds[EXPUL] = ft_strdup("expulse\n");
	env->cmds[BROAD] = ft_strdup("broadcast ");
	env->cmds[INCANT] = ft_strdup("incantation\n");
	env->cmds[FORK] = ft_strdup("fork\n");
	env->cmds[CON_NB] = ft_strdup("connect_nbr\n");
	return (OK);
}

static int			init_responces(t_env *env)
{
	if (!(env->resp = (int *)malloc(NB_RESP * sizeof(int))))
		return (ERR);
	ft_bzero(env->resp, (NB_RESP * sizeof(int)));
	return (OK);
}

static void			ft_set_env(t_env *env)
{
	env->addr = NULL;
	env->port = 0;
	env->dead = 0;
	env->elevating = 0;
	env->moved = 0;
	env->dir_msg = -1;
	env->dir_chg = 0;
	env->forked = 0;
	env->laying = 0;
	env->my_incant = 0;
	env->connect_nb = -1;
	env->expul = 0;
	env->level = 1;
	env->team = NULL;
	env->view = NULL;
	env->moves = NULL;
	env->buffer = NULL;
	env->inv[0] = -1;
}


t_env				*get_env(void)
{
	static t_env	*env = NULL;

	if (!env)
	{
		if (!(env = (t_env *)malloc(sizeof(t_env)))
				|| (init_cmd_tab(env) == ERR)
				|| (init_responces(env) == ERR)
				|| (ft_init_incantation(env) == ERR))
		{
			error("Malloc Failed env");
			return (NULL);
		}
		ft_set_env(env);
	}
	return (env);
}
