/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 19:39:44 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/14 12:40:56 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"

void				ft_del_cmd_lst(void *content, size_t content_size)
{
	t_cmd			*tmp;

	tmp = (t_cmd *)content;
	free(tmp->cmd);
	if (tmp->opt)
		free(tmp->opt);
	ft_lstdel_elem(content, content_size);
}

int					ft_expecting_resp(t_env *env)
{
	int				i;

	i = 0;
	while (i < NB_RESP)
	{
		if (env->resp[i] > 0)
		{
			printf("EXPECTING A RESPONSE\n");
			return (YES);
		}
		++i;
	}
	printf("NOT WAITING FOR A RESPONSE\n");
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
		printf("EXPECTING %d RESPONSE[%s]\n", env->resp[i], str );
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

	printf("IN SEND MOVES\n");
	i = 0;
	ptr = env->moves;
	str = NULL;
	while (ptr && i < 10)
	{
		str = ft_strjoin(CMD(ptr)->cmd, CMD(ptr)->opt);
		printf("STR IS [%s]\n",str );
		ft_send_cmd(env, str, CMD(ptr)->resp);
		free(str);
		ptr = ptr->next;
		++i;
	}
	if (ptr)
	{
		printf("sent 10 commands but still have some in list\n");
		while (env->moves != ptr)
		{
			tmp = env->moves;
			env->moves = env->moves->next;
			ft_lstdelone(&tmp, ft_del_cmd_lst);
		}
	}
	else if (env->moves)
	{
		printf("DELETING MOVES\n");
		ft_lstdel(&env->moves, ft_del_cmd_lst);
		env->moves = NULL;
	}
	printf("END OF SEND MOVES\n");
	return (OK);
}

int					ft_takemove(t_env *env)
{
	printf("IN TAKEMOVE\n");
	ft_print_responsetab(env);
	if (env->elevating || ft_expecting_resp(env))
	{
		printf("TAKEMOVE - waitig to elevate or for a response\n");
		return (OK);
	}
	else
	{
		if (!env->moves)
		{
			printf("I DONT HAVE ANY MOVES\n");
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
	/*int				i;
	  char			*str;*/

	/*i = 0;
	  ft_send_cmd(env, FORW, RESP_OK);
	  ft_send_cmd(env, LEFT, RESP_OK);
	  ft_send_cmd(env, RIGHT, RESP_OK);
	  ft_send_cmd(env, VIEW, RESP_VIEW);*/
	/*	env->resp[RESP_OK] += 2;
		if ((send(env->socket, "avance\n", ft_strlen("avance\n"), 0)) < 0)
		return (error("Failed to send command"));
		if ((send(env->socket, "gauche\n", ft_strlen("gauche\n"), 0)) < 0)
		return (error("Failed to send command"));*/
	ft_look(env);
	while (!env->dead)
	{
		print_moves(env);
		ft_recv(env);
		ft_takemove(env);
		/*++i;*/
	}
	return (OK);
}
