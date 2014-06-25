/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 19:25:39 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/24 20:08:40 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include "client.h"

int					ft_fork(t_env *env)
{
	pid_t			father;
	char			*str;
	char			**args;

	if ((father = fork()) == -1)
		return (error("Failed to fork"));
	if (!father)
	{
		asprintf(&str, "%s -n %s -p %d -h %s", env->path, env->team, env->port,
				env->addr);
		args = ft_strsplit(str, ' ');
		execve(env->path, args, env->envp);
		ft_free_tab((void ***)&args);
		ft_strdel(&str);
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
