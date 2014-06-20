/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:15:48 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/20 15:26:00 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include "serveur.h"

static void		st_loop(char **join, char **tmp, t_list *list)
{
	*tmp = ft_strjoin(*join, list->next->content);
	ft_memdel((void **)join);
	*join = ft_strdup(*tmp);
	ft_memdel((void **)tmp);
}

void			client_write(t_env *env, int cs)
{
	char		*join;
	char		*tmp;
	t_list		*list;

	if (env->fd_socket[cs].type == FREE)
		return ;
	tmp = NULL;
	join = NULL;
	list = env->fd_socket[cs].line;
	if (list != NULL)
	{
		join = ft_strjoin(list->content, NULL);
		while (list->next != NULL)
		{
			st_loop(&join, &tmp, list);
			list = list->next;
		}
		tmp = ft_strjoin(join, env->fd_socket[cs].buf_write);
		ft_memdel((void **)&join);
	}
	else
		tmp = ft_strdup(env->fd_socket[cs].buf_write);
	printf("SEND TO [%d] : [%s]\n", cs, tmp);
	if (send(cs, tmp, ft_strlen(tmp), 0) == -1)
		printf("pb send socket [%d]\n", cs);
	ft_lstdel(&env->fd_socket[cs].line, ft_del);
	ft_memdel((void **)&tmp);
	ft_bzero(env->fd_socket[cs].buf_write, BUF_SIZE);
}
