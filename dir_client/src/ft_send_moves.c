/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 21:03:55 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/24 22:51:46 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include "client.h"

void				ft_del_cmd_lst(void *content, size_t content_size)
{
	t_cmd			*tmp;

	tmp = (t_cmd *)content;
	if (tmp)
	{
		free(tmp->cmd);
		if (tmp->opt)
			free(tmp->opt);
		ft_bzero(content, content_size);
		free(tmp);
	}
}

static int			ft_send_cmd(t_env *env, char *cmd, int i)
{
	if (i >= 0)
		env->resp[i]++;
	if ((send(env->socket, cmd, ft_strlen(cmd), 0)) < 0)
	{
		if (i >= 0)
			env->resp[i]--;
		return (error("Failed to send command"));
	}
	return (OK);
}

static void			ft_clean_moves(t_env *env, t_list *ptr)
{
	t_list			*tmp;

	if (ptr)
	{
		while (env->moves != ptr)
		{
			tmp = env->moves;
			env->moves = env->moves->next;
			ft_lstdelone(&tmp, ft_del_cmd_lst);
		}
	}
	else if (env->moves)
	{
		ft_lstdel(&env->moves, ft_del_cmd_lst);
		env->moves = NULL;
	}
}

int					ft_send_moves(t_env *env)
{
	t_list			*ptr;
	int				i;
	char			*str;

	i = 0;
	ptr = env->moves;
	str = NULL;
	while (ptr && i < 10)
	{
		str = ft_strjoin(CMD(ptr)->cmd, CMD(ptr)->opt);
		ft_send_cmd(env, str, CMD(ptr)->resp);
		free(str);
		ptr = ptr->next;
		++i;
	}
	ft_clean_moves(env, ptr);
	return (OK);
}
