/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reply_in_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 12:24:49 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/11 18:16:04 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_push_msg(t_env *env, int cs)
{
	char			*push;

	push = ft_strdup(env->fd_socket[cs].buf_write);
	ft_lstpush(&env->fd_socket[cs].line, ft_lstnew(push, ft_strlen(push) + 1));
	ft_bzero(env->fd_socket[cs].buf_write, BUF_SIZE);
}

void				ft_reply_in_buff(t_env *env, int cs, char *msg)
{
	char			*res;
	char			*tmp;

	res = ft_strdup(msg);
	if (res && res[ft_strlen(res) - 1] != '\n')
	{
		tmp = ft_strjoin(res, "\n");
		ft_memdel((void **)&res);
		res = tmp;
	}
	if (env->fd_socket[cs].buf_write[0] != '\0')
		ft_push_msg(env, cs);
	ft_strncpy(env->fd_socket[cs].buf_write, res, ft_strlen(res));
	ft_memdel((void **)&res);
}
