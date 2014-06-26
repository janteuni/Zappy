/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reply_in_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 12:24:49 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/19 12:35:08 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_push_msg(t_env *env, int cs)
{
	char			*push;

	push = env->fd_socket[cs].buf_write;
	ft_lstpush(&env->fd_socket[cs].line, ft_lstnew(push, ft_strlen(push) + 1));
	ft_bzero(env->fd_socket[cs].buf_write, BUF_SIZE);
}

static void			st_push_res(t_env *env, int cs, char *res)
{
	res[ft_strlen(res) - 1] = '\0';
	ft_lstpush(&env->fd_socket[cs].line, ft_lstnew(res, ft_strlen(res) + 1));
	ft_strncpy(env->fd_socket[cs].buf_write, "\n", 1);
}

void				ft_reply_in_buff(t_env *env, int cs, char *msg)
{
	char			*res;
	char			*tmp;

	res = ft_strdup(msg);
	if (env->fd_socket[cs].type == FREE)
		return ;
	if (res && res[ft_strlen(res) - 1] != '\n')
	{
		tmp = ft_strjoin(res, "\n");
		ft_memdel((void **)&res);
		res = tmp;
	}
	if (env->fd_socket[cs].buf_write[0] != '\0')
		ft_push_msg(env, cs);
	if (ft_strlen(res) >= BUF_SIZE)
		st_push_res(env, cs, res);
	else
		ft_strncpy(env->fd_socket[cs].buf_write, res, ft_strlen(res));
	ft_memdel((void **)&res);
}
