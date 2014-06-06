/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 11:20:23 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/06 19:42:12 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include "client.h"

int			init_env(t_env *env)
{
	/*int				i;
	struct rlimit	rlp;*/

	/*i = 0;*/
	/*env->fd_socket = NULL;*/
	/*if (getrlimit(RLIMIT_NOFILE, &rlp) == -1)
		return (error("getrlimit failed"));
	env->max_fd = rlp.rlim_cur;*/
	/*if (!(env->fd_socket = (t_fd *)malloc(sizeof(t_fd))))
		return (error("malloc failed"));*/
	/*while (i < env->max_fd)
	{
		clean_fd(&env->fd_socket[i]);
		i++;
	}*/
	clean_fd(env);
	return (OK);
}

int			main(int ac, char **av)
{
	t_env	*env;

	env = get_env();
	/*if (ft_parse(ac, av, env) < 0)
	{
		ft_free_env(env);
		return (ERR)
		}*/
	if (init_env(env) == ERR)
		return (ERR);
	if (ft_parse(ac, av, env) == ERR)
		return (ERR);
	if (create_client(env) == ERR)
		return (ERR);
	ft_loop(env);
	close(env->socket);
	return (OK);
}
