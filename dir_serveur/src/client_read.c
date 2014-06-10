/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 18:12:41 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/10 18:58:28 by janteuni         ###   ########.fr       */
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
		ft_receive(env, cs);
	}
}
