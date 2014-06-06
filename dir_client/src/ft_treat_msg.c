/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 11:25:29 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/06 11:19:49 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char				*ft_get_msg(t_env *env, int cs, char *msg)
{
	char		*join;
	char		*tmp;
	t_list		*list;

	tmp = NULL;
	join = NULL;
	list = env->fd_socket[cs].line_read;
	if (list != NULL)
	{
		join = ft_strjoin((char *)list->content, NULL);
		while (list->next != NULL)
		{
			tmp = ft_strjoin(join, list->next->content);
			ft_memdel((void **)&join);
			join = ft_strdup(tmp);
			ft_memdel((void **)&tmp);
			list = list->next;
		}
		tmp = ft_strjoin(join, msg);
		ft_memdel((void **)&join);
	}
	else
		tmp = ft_strdup(msg);
	ft_lstdel(&env->fd_socket[cs].line_read, ft_del);
	return (tmp);
}

void				ft_treat_msg(t_env *env, int cs, char *msg)
{
	char			*rcv;

	rcv = ft_get_msg(env, cs, msg);
	ft_treat_cmd(rcv, env, cs);
	ft_memdel((void **)&rcv);
}
