/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:12:41 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/18 12:39:13 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "serveur.h"

void				client_read(t_env *env, int cs)
{
	env->fd_socket[cs].buf_offset = read(cs, env->fd_socket[cs].buf_read
			+ env->fd_socket[cs].buf_offset,
			BUF_SIZE - env->fd_socket[cs].buf_offset);
	if (env->fd_socket[cs].buf_offset <= 0)
	{
		close(cs);
		clean_fd(&env->fd_socket[cs]);
		printf("client #%d gone away\n", cs);
	}
	else
	{
		printf("READ : [%s]\n", env->fd_socket[cs].buf_read);
		ft_receive(env, cs);
	}
}
