/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:23:39 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/20 13:12:48 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	check_fd(t_env *env)
{
	int	i;

	i = 0;
	while ((i < env->max_fd) && (env->r > 0))
	{
		if (FD_ISSET(i, &env->fd_read))
		{
			if (env->fd_socket[i].fct_read != NULL)
				env->fd_socket[i].fct_read(env, i);
		}
		if (FD_ISSET(i, &env->fd_write))
		{
			if (env->fd_socket[i].fct_write != NULL)
				env->fd_socket[i].fct_write(env, i);
		}
		if (FD_ISSET(i, &env->fd_read) ||
				FD_ISSET(i, &env->fd_write))
			env->r--;
		i++;
	}
}
