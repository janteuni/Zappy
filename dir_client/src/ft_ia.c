/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 12:00:55 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/19 15:01:48 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "client.h"

int					ft_random(t_env *env)
{
	int				n;

    srand(time(NULL));
	n = rand() % 8;
	if (n == 1 || n == 0)
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	else if (n < 6)
		ft_dir_left(env, n);
	else
		ft_dir_right(env, n);
	env->dir_chg = 0;
	printf("RANDOM MOVE [%d]\n", n);
	return (OK);
}

int					ft_push_cmd(t_env *env, int cmd_num, char *opt, int resp)
{
	t_cmd			cmd;

	printf("PUSH COMMAND [%s]\n", env->cmds[cmd_num] );
	cmd.cmd = ft_strdup(env->cmds[cmd_num]);
	cmd.opt = opt;
	cmd.resp = resp;
	ft_lstpush(&env->moves, ft_lstnew(&cmd, sizeof(t_cmd)));
	return (OK);
}

int					ft_take_all(t_env *env)
{
	int				i;

	i = 0;
	while (/*i < env->view[0][FOOD] &&*/ i < 5)
	{
		ft_push_cmd(env, PREND, ft_strdup(ft_get_str(FOOD)), RESP_OK);
		++i;
	}
	return (OK);
}

int					ft_find(t_env *env, int obj)
{
	int				i;
	int				c;

	c = -1;
	i = 1;
	if (env->view[0][obj] == 0)
	{
		while (i < (env->level + 1) * (env->level + 1))
		{
			if (env->view[i][obj] > 0
					&& (c < 0 || env->view[c][DIST] > env->view[i][DIST]))
				c = i;
			++i;
		}
		if (c > 0)
		{
			env->dir_chg = 0;
			ft_get_route(env, c);
		}
		else
		{
			if (env->dir_chg < 4)
			{
				ft_push_cmd(env, DROITE, NULL, RESP_OK);
				env->dir_chg++;
			}
			else
			{
				env->dir_chg = 0;
				ft_random(env);
			}
			return (OK);
		}
	}
	if (obj == FOOD)
		ft_take_all(env);
	else
		ft_push_cmd(env, PREND, ft_strdup(ft_get_str(obj)), RESP_OK);
	return (OK);
}

int					ft_ia(t_env *env)
{
	printf("WELCOME TO THE IA \n");
	if (env->laying)
	{
		printf("i am laying so push connect_nb\n");
		ft_push_cmd(env, CON_NB, NULL, RESP_VAL);
	}
	if (env->inv[0] < 0)
	{
		printf("not yet gt inventory - push inventory\n");
		ft_push_cmd(env, INVENT, NULL, RESP_INV);
		return (OK);
	}
	if (env->inv[FOOD] < 2)
	{
		printf("Food is less than 2 - find food\n");
		ft_find(env, FOOD);
	}
	else if (!env->forked && !env->laying)
	{
		if (env->connect_nb < 0)
		{
			printf("not got a connect number - push connect_nb\n");
			ft_push_cmd(env, CON_NB, NULL, RESP_VAL);
		}
		else if (ft_enough_food(env))
		{
			printf("push fork\n");
			ft_push_cmd(env, FORK, NULL, RESP_OK);
			env->laying = 1;
		}
		else
		{
			printf("find food so can fork\n");
			ft_find(env, FOOD);
		}
	}
	/*	else if (env->laying && !env->forked)
		ft_find(env, FOOD);*/
	else if (!env->forked && env->laying && env->inv[FOOD] < 8)
	{
		printf("layed egg but not yet forked - finding food to get at least 8\n");
		ft_find(env, FOOD);
	}
	else /* have forked, food > 2, im free to do an incantation */
	{
		//COLLECT STONES & DO INCANTATION
		if (ft_check_squ_stones(env))
		{
			printf("the stones are on the square - broadcast message\n");
			ft_get_people_here(env);
		}
		else if (ft_check_inv_stones(env))
		{
			printf("the stones are in my inventory - putting them down and then broadcasting\n");
			ft_putdown_stones(env);
			ft_get_people_here(env);
		}
		else
		{
			printf("have not got the stones I need - going to find them\n");
			ft_find_stones(env);
		}
	}
	ft_push_cmd(env, INVENT, NULL, RESP_INV);
	ft_push_cmd(env, VOIR, NULL, RESP_VIEW);
	return (OK);
}

