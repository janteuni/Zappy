/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_follow_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 17:13:07 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/20 14:59:49 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void				ft_dir_right(t_env *env, int dir)
{
	if (dir == 6)
	{
		ft_push_cmd(env, DROITE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
		ft_push_cmd(env, DROITE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	}
	else if (dir == 7)
	{
		ft_push_cmd(env, DROITE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	}
	else if (dir == 8)
	{
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
		ft_push_cmd(env, DROITE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	}
}

void				ft_dir_left(t_env *env, int dir)
{
	if (dir == 2)
	{
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
		ft_push_cmd(env, GAUCHE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	}
	else if (dir == 3)
	{
		ft_push_cmd(env, GAUCHE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	}
	else if (dir == 4)
	{
		ft_push_cmd(env, GAUCHE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
		ft_push_cmd(env, GAUCHE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	}
	else if (dir == 5)
	{
		ft_push_cmd(env, GAUCHE, NULL, RESP_OK);
		ft_push_cmd(env, GAUCHE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	}
}

int					ft_follow_msg(t_env *env)
{
	/*delete previous moves?*/
	dprintf(env->aff, "IN FOLLOW MSG - following direction [%d]\n", env->dir_msg);
	ft_lstdel(&env->moves, ft_del_cmd_lst);
	env->moves = NULL;
	/* go to correct squ*/
	if (env->laying)
	{
		dprintf(env->aff, "i am laying so push connect_nb\n");
		ft_push_cmd(env, CON_NB, NULL, RESP_VAL);
	}
	if (env->dir_msg == 1)
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	else if (env->dir_msg > 1 && env->dir_msg < 6)
		ft_dir_left(env, env->dir_msg);
	else if (env->dir_msg > 5)
		ft_dir_right(env, env->dir_msg);
	/*mark flag as read*/
	env->dir_msg = -1;
	return (OK);
}

