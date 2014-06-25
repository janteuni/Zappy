/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:15:48 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/25 17:30:48 by janteuni         ###   ########.fr       */
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

static void		st_clean(t_env *env, char *tmp, int cs)
{
	if (cs == env->graphic && ft_strstr(tmp, "seg ") != NULL)
	{
		printf("END\n");
		env->end = YES;
	}
	ft_lstdel(&(env->fd_socket[cs].line), ft_del);
	ft_bzero(env->fd_socket[cs].buf_write, BUF_SIZE);
	if (cs != env->graphic
			&& env->fd_socket[cs].type == CLIENT
			&& ft_strstr(tmp, "mort\n") != NULL)
		clean_fd(&env->fd_socket[cs]);
	ft_memdel((void **)&tmp);
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
	if (send(cs, tmp, ft_strlen(tmp), 0) == -1)
		printf("pb send socket [%d]\n", cs);
	st_clean(env, tmp, cs);
}
