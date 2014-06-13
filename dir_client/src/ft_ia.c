/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 12:00:55 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/13 21:23:34 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
/*
int					ft_set_cmd(t_cmd *cmd, int cmd_num, int resp, t_env *env)
{
	cmd->cmd = env->cmds[cmd_num];
	cmd->opt = NULL;
	cmd->resp = resp;
	return (OK);
}

int					ft_set_cmd_opt(t_cmd *cmd, int cmd_num, char *opt,
		t_env *env)
{
	cmd->cmd = env->cmds[cmd_num];
	cmd->opt = opt;
	cmd->resp = RESP_OK;
	return (OK);
}*/

int					ft_push_cmd(t_env *env, int cmd_num, char *opt, int resp)
{
	t_cmd			cmd;

	cmd.cmd = ft_strdup(env->cmds[cmd_num]);
	cmd.opt = opt;
	cmd.resp = resp;
	ft_lstpush(&env->moves, ft_lstnew(&cmd, sizeof(t_cmd)));
	return (OK);
}

int					ft_find_food(t_env *env)
{
	int				i;
	int				c;

	c = -1;
	i = 1;
	if (env->view[0][FOOD] == 0)
	{
		while (i < (env->level + 1) * (env->level + 1))
		{
			if (env->view[i][FOOD] > 0
					&& (c < 0 || env->view[c][DIST] > env->view[i][DIST]))
				c = i;
			++i;
		}
		ft_get_route(env, c);
	}
	ft_push_cmd(env, PREND, ft_strdup("nourriture\n"), RESP_OK);
	return (OK);
}

int					ft_ia(t_env *env)
{
	printf("IA IS STARTING\n");
	if (env->laying)
		ft_push_cmd(env, CON_NB, NULL, RESP_VAL);
	if (env->inv[0] < 0)
		ft_push_cmd(env, INVENT, NULL, RESP_INV);
	else if (!env->forked && !env->laying)
	{
		printf("current connect_nb = %d\n",env->connect_nb );
		if (env->connect_nb < 0)
			ft_push_cmd(env, CON_NB, NULL, RESP_VAL);
		else if (ft_enough_food(env))
		{
			ft_push_cmd(env, FORK, NULL, RESP_OK);
			env->laying = 1;
		}
		else
			ft_find_food(env);
	}
	return (OK);
}

