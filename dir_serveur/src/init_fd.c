/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:17:39 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/07 15:34:58 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include <sys/select.h>

void		init_fd(t_env *env)
{
	int		i;

	i = 0;
	env->max = 0;
	FD_ZERO(&env->fd_read);
	FD_ZERO(&env->fd_write);
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type != FREE)
		{
			FD_SET(i, &env->fd_read);
			if (ft_strlen(env->fd_socket[i].buf_write) > 0)
			{
				printf("init write\n");
				FD_SET(i, &env->fd_write);
			}
			env->max = MAX(env->max, i);
		}
		i++;
	}
}
