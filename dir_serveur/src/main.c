/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 11:20:23 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/06 18:35:53 by janteuni         ###   ########.fr       */
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
	env->teams = NULL;
	env->max_team = 0;
	env->width = 0;
	env->height = 0;
	env->time = 0;
	env->nb_player = 0;
	env->port = 0;
	env->map = NULL;
	return (OK);
}

void		print_params(t_env *env)
{
	int	i;

	i = 0;
	printf("port : %d\nwidth: %d\nheight: %d\n", env->port, env->width, env->height);
	printf("time : %d\n", env->time);
	printf("nb_player : %d\n", env->nb_player);
	printf("--------------------TEANS-------------------\n");
	printf("max_team: %d\n",env->max_team);
	while (i < env->max_team)
	{
		printf("name %s\n", env->teams[i].name);
		i++;
	}
	printf("--------------------------------------------\n");

}

int			main(int argc, char **argv)
{
	t_env	*env;

	env = get_env();
	if (init_env(env) == ERR)
		return (ERR);
	if (parser(env, argc, argv) == ERR)
		return (ERR);
	print_params(env);
	if (create_server(env) == ERR)
		return (ERR);
	ft_init_map(env);
	ft_print_map(env, SIBUR);
	ft_loop(env);
	close(env->sock_server);
	return (OK);
}
