/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 11:20:23 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/25 16:38:46 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include <sys/socket.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include "client.h"

static int			ft_treat_msg(t_env *env, char *buf)
{
	char			**msgs;
	char			**coords;

	msgs = ft_strsplit(buf, '\n');
	if (ft_tab_len(msgs) < 2)
		return (error(msgs[0]));
	env->connect_nb = ft_atoi(msgs[0]);
	coords = ft_strsplit(msgs[1], ' ');
	if (ft_tab_len(coords) < 2)
		return (error("Failed to receive coordinates"));
	env->x = ft_atoi(coords[0]);
	env->y = ft_atoi(coords[1]);
	ft_free_tab((void ***)&msgs);
	ft_free_tab((void ***)&coords);
	return (OK);
}

int					ft_confirm_connection(t_env *env)
{
	char			buf[BUF_SIZE + 1];
	int				n;
	char			*str;

	ft_bzero(buf, BUF_SIZE + 1);
	recv(env->socket, buf, BUF_SIZE, 0);
	if (ft_strcmp("BIENVENUE\n", buf))
		return (ERR);
	str = ft_strjoin(env->team, "\n");
	if ((n = send(env->socket, str, ft_strlen(str), 0)) < 0)
		return (error("Failed to send teamname"));
	ft_bzero(buf, BUF_SIZE + 1);
	recv(env->socket, buf, BUF_SIZE, 0);
	free(str);
	if (ft_treat_msg(env, buf) < 0)
		return (ERR);
	return (OK);
}

int					main(int ac, char **av, char **envp)
{
	t_env			*env;

	if (!(env = get_env()))
		return (ERR);
	env->path = av[0];
	env->envp = envp;
	if (ft_setup_signal() == ERR)
		return (error("Failed to setup signals"));
	if (ft_parse(ac, av, env) == ERR)
		return (ERR);
	if (create_client(env) == ERR)
		return (ERR);
	if (ft_confirm_connection(env) == ERR)
		return (error("Failed to connect"));
	ft_loop(env);
	close(env->socket);
	return (OK);
}
