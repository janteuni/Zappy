/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:23:39 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/07 15:51:20 by janteuni         ###   ########.fr       */
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
			env->fd_socket[i].fct_read(env, i);
		if (FD_ISSET(i, &env->fd_write))
			env->fd_socket[i].fct_write(env, i);
		if (FD_ISSET(i, &env->fd_read) ||
				FD_ISSET(i, &env->fd_write))
			env->r--;
		i++;
	}
}
