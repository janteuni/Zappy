/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 19:39:44 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/20 15:04:42 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		/*ft_lstdel_elem(content, content_size);*/
		ft_bzero(content, content_size);
		free(tmp);
	}
}

int					ft_expecting_resp(t_env *env)
{
	int				i;

	i = 0;
	while (i < NB_RESP)
	{
		if (env->resp[i] > 0)
		{
			dprintf(env->aff, "[%d]\twaiting for a response\n", env->pid);
			return (YES);
		}
		++i;
	}
	return (NO);
}

int					ft_print_responsetab(t_env *env)
{
	int				i;
	char			*str;

	i = 0;
	while (i < NB_RESP)
	{
		if (i == 0)
			str = "OK / KO";
		else if (i == 1)
			str = "VIEW";
		else if (i == 2)
			str = "INVENTORY";
		else
			str = "VALUE";
		dprintf(env->aff, "[%d]\tEXPECTING %d RESPONSE[%s]\n",env->pid, env->resp[i], str );
		++i;
	}
	return (OK);
}

int					ft_send_moves(t_env *env)
{
	t_list			*ptr;
	t_list			*tmp;
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
	return (OK);
}

int					ft_takemove(t_env *env)
{
	ft_print_responsetab(env);
	if (env->elevating || ft_expecting_resp(env))
	{
		return (OK);
	}
	else
	{
		if (!env->elevating && env->dir_msg >= 0)
		{
			ft_follow_msg(env);
		}
		else if (!env->moves)
		{
			ft_ia(env);
		}
		ft_send_moves(env);
	}
	return (OK);
}

void				print_moves(t_env *env)
{
	t_list			*ptr;
	int				i;

	ptr = env->moves;
	i = 0;
	if (ptr)
		printf("MOVES TO TAKE:\n");
	while (ptr)
	{
		printf("MOVE %d : %s\n",i, CMD(ptr)->cmd );
		ptr = ptr->next;
		i++;
	}
}

int					ft_loop(t_env *env)
{
	ft_look(env);
	while (!env->dead)
	{
		/*		print_moves(env);*/
		ft_recv(env);
		if (!env->dead)
			ft_takemove(env);
	}
	ft_free_env(&env);
	return (OK);
}
