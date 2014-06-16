/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_follow_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 17:13:07 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/16 19:56:06 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void			ft_dir_msg_right(t_env *env)
{
	if (env->dir_msg == 6)
	{
		ft_push_cmd(env, DROITE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
		ft_push_cmd(env, DROITE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	}
	else if (env->dir_msg == 7)
	{
		ft_push_cmd(env, DROITE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	}
	else if (env->dir_msg == 8)
	{
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
		ft_push_cmd(env, DROITE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	}
}

static void			ft_dir_msg_left(t_env *env)
{
	if (env->dir_msg == 2)
	{
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
		ft_push_cmd(env, GAUCHE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	}
	else if (env->dir_msg == 3)
	{
		ft_push_cmd(env, GAUCHE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	}
	else if (env->dir_msg == 4)
	{
		ft_push_cmd(env, GAUCHE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
		ft_push_cmd(env, GAUCHE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	}
	else if (env->dir_msg == 5)
	{
		ft_push_cmd(env, GAUCHE, NULL, RESP_OK);
		ft_push_cmd(env, GAUCHE, NULL, RESP_OK);
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	}
}

int					ft_follow_msg(t_env *env)
{
	/*delete previous moves?*/
	ft_lstdel(&env->moves, ft_del_cmd_lst);
	env->moves = NULL;
	/* go to correct squ*/
	if (env->dir_msg == 1)
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	else if (env->dir_msg > 1 && env->dir_msg < 6)
		ft_dir_msg_left(env);
	else if (env->dir_msg > 5)
		ft_dir_msg_right(env);
	/*mark flag as read*/
	env->dir_msg = -1;
	return (OK);
}

