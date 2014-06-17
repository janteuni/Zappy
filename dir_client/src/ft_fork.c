/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 19:25:39 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/17 22:02:10 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include "client.h"

int					ft_reset_env(t_env *env)
{
	env->dead = 0;
	env->elevating = 0;
	env->moved = 0;
	env->dir_msg = 0;
	env->forked = 0;
	env->laying = 0;
	env->connect_nb = -1;
	env->level = 1;
	env->view = NULL;
	env->moves = NULL;
	ft_bzero(env->inv, sizeof(int) * INV_SIZE);
	return (OK);
}

int					ft_connect_egg(t_env *env)
{
	int				i;
	int				connected;

	printf("IN SON - CONNECTING EGG\n");
	i = 0;
	connected = 0;
	while (i < 5 && !connected)
	{
		if (create_client(env) == OK && ft_confirm_connection(env) == OK)
		{
			connected = 1;
			return (OK);
		}
		++i;
	}
	return (ERR);
}

int					ft_fork(t_env *env)
{
	pid_t			father;
	char			*str;
	char			**args;

	printf("GOING TO FORK\n");
	if ((father = fork()) == -1)
		return (error("Failed to fork"));
	if (!father)
	{
	/*	ft_reset_env(env);
		if (ft_connect_egg(env) == ERR)
		{
		ft_putendl("Egg failed to connect to server - exiting");
		ft_free_and_quit(env);
		}
		env->pid = getpid();*/
		asprintf(&str, "%s -n %s -p %d -h %s", env->path, env->team, env->port, env->addr);
		printf("STR SO FAR [%s]\n",str );
		args = ft_strsplit(str, ' ');
		execve(env->path, args, env->envp);
		ft_putendl("Failed to execute program - exiting");
		ft_free_and_quit(env);
	}
	else
	{
		env->laying = 0;
		env->forked = 1;
	}
	return (OK);
}
