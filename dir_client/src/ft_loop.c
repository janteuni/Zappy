/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 19:39:44 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/25 16:38:12 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int			ft_expecting_resp(t_env *env)
{
	int				i;

	i = 0;
	while (i < NB_RESP)
	{
		if (env->resp[i] > 0)
		{
			return (YES);
		}
		++i;
	}
	return (NO);
}

int					ft_takemove(t_env *env)
{
	if (env->elevating || ft_expecting_resp(env))
		return (OK);
	else
	{
		if (env->inv[FOOD] < 8)
			ft_find(env, FOOD);
		else if (!env->elevating && env->dir_msg >= 0)
			ft_follow_msg(env);
		else if (!env->moves)
			ft_ia(env);
		ft_push_cmd(env, INVENT, NULL, RESP_INV);
		ft_push_cmd(env, VOIR, NULL, RESP_VIEW);
		ft_send_moves(env);
	}
	return (OK);
}

int					ft_loop(t_env *env)
{
	ft_push_cmd(env, INVENT, NULL, RESP_INV);
	ft_push_cmd(env, VOIR, NULL, RESP_VIEW);
	ft_send_moves(env);
	while (!env->dead)
	{
		ft_recv(env);
		if (!env->dead)
			ft_takemove(env);
	}
	ft_free_env(&env);
	return (OK);
}
