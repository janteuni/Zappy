/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 12:00:55 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/12 19:33:12 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int					ft_set_cmd(t_cmd *cmd, int cmd_num, char *opt, int resp, t_env *env)
{
	cmd->cmd = env->cmds[cmd_num];
	cmd->opt = opt;
	cmd->resp = resp;
	return (OK);
}
/*
int					ft_find_food(t_env *env)
{
	int				nb;
	int				i;

	if (env->view[0][FOOD] == 0)
	{
		nb = (env->level + 1) * (env->level + 1);
		i = 0;
		while (i < nb)
		{
			if (
			++i;


	}

}
*/
int					ft_ia(t_env *env)
{
	t_cmd			cmd;

	if (!env->inv)
	{
		ft_set_cmd(&cmd, INVENT, NULL, RESP_INV, env);
		ft_lstadd(&env->moves, ft_lstnew(&cmd, sizeof(t_cmd)));
	}
	else if (!env->forked)
	{
		if (env->connect_nb < 0)
		{
			ft_set_cmd(&cmd, CON_NB, NULL, RESP_VAL, env);
			ft_lstadd(&env->moves, ft_lstnew(&cmd, sizeof(t_cmd)));
		}
		else if (ft_enough_food(env))
		{
			if ( env->connect_nb > 0)
			{
				ft_set_cmd(&cmd, FORK, NULL, RESP_OK, env);
				ft_lstadd(&env->moves, ft_lstnew(&cmd, sizeof(t_cmd)));
			}
		}
/*		else
			ft_find_food(env);*/
	}
	return (OK);
}

