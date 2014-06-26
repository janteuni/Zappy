/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 12:00:55 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/24 22:16:20 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int					ft_push_cmd(t_env *env, int cmd_num, char *opt, int resp)
{
	t_cmd			cmd;

	cmd.cmd = ft_strdup(env->cmds[cmd_num]);
	cmd.opt = opt;
	cmd.resp = resp;
	ft_lstpush(&env->moves, ft_lstnew(&cmd, sizeof(t_cmd)));
	return (OK);
}

static void			ft_lay_egg(t_env *env)
{
	if (env->connect_nb < 0)
		ft_push_cmd(env, CON_NB, NULL, RESP_VAL);
	else if (ft_enough_food(env))
	{
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
		ft_push_cmd(env, FORK, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
		env->laying = 1;
	}
	else
		ft_find(env, FOOD);
}

static void			ft_try_elevation(t_env *env)
{
	if (env->view[0][FOOD] > 0 && ft_check_squ_stones(env))
		ft_get_people_here(env);
	else if (ft_check_inv_stones(env))
	{
		if (env->view[0][FOOD] == 0)
			ft_find(env, FOOD);
		else
		{
			ft_putdown_stones(env);
			ft_get_people_here(env);
		}
	}
	else
		ft_collect_stones(env);
}

int					ft_ia(t_env *env)
{
	if (env->laying)
		ft_push_cmd(env, CON_NB, NULL, RESP_VAL);
	if (env->expul)
	{
		ft_push_cmd(env, EXPUL, NULL, RESP_OK);
		env->expul = 0;
	}
	if (!env->forked && !env->laying)
		ft_lay_egg(env);
	else if (!env->forked && env->laying && env->inv[FOOD] < 12)
		ft_find(env, FOOD);
	else
		ft_try_elevation(env);
	return (OK);
}
