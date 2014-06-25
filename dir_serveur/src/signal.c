/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 16:00:48 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/25 17:04:44 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/socket.h>
#include "serveur.h"

static void			st_special_quit(t_env *env)
{
	int				i;

	i = 0;
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type == CLIENT && i != env->graphic)
		{
			printf("mort de %d LEVEL %d\n", i, env->fd_socket[i].level);
			send(i, "mort\n", 5, 0);
		}
		i++;
	}
}

void				ft_ctr_c(int i)
{
	t_env		*env;

	(void)i;
	env = get_env();
	st_special_quit(env);
	ft_exit("ctr c signal");
}
