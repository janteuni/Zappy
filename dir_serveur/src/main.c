/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 11:20:23 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/06 11:14:34 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include "serveur.h"

int			init_env(t_env *env)
{
	int				i;
	struct rlimit	rlp;

	i = 0;
	env->fd_socket = NULL;
	if (getrlimit(RLIMIT_NOFILE, &rlp) == -1)
		return (error("getrlimit failed"));
	env->max_fd = rlp.rlim_cur;
	if (!(env->fd_socket = (t_fd *)malloc(sizeof(*env->fd_socket)
					* env->max_fd)))
		return (error("malloc failed"));
	while (i < env->max_fd)
	{
		clean_fd(&env->fd_socket[i]);
		i++;
	}
	return (OK);
}

int			main(int argc, char **argv)
{
	t_env	*env;

	env = get_env();
	if (init_env(env) == ERR)
		return (ERR);
	if (parser(env, argc, argv) == ERR)
		return (ERR);
	if (create_server(env) == ERR)
		return (ERR);
	ft_loop(env);
	close(env->sock_server);
	return (OK);
}
