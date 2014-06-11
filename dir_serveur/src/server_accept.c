/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_accept.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:30:04 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/11 12:39:52 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include "serveur.h"

void					st_init_inventory(t_env *env, int cs)
{
	int					i;

	i = 1;
	env->fd_socket[cs].inventory[FOOD] = 10;
	while (i < NB_STUFF)
	{
		env->fd_socket[cs].inventory[i] = 0;
		i++;
	}
}

void					server_accept(t_env *env)
{
	int					cs;
	struct sockaddr_in	csin;
	socklen_t			csin_len;

	csin_len = sizeof(csin);
	cs = accept(env->sock_server, (struct sockaddr*)&csin, &csin_len);
	if (cs == -1)
		exit(0);
	ft_putendl("NEW CLIENT IS CONNECTED..");
	clean_fd(&env->fd_socket[cs]);
	env->fd_socket[cs].type = CLIENT;
	env->fd_socket[cs].my_cs = cs;
	env->fd_socket[cs].fct_read = client_read;
	env->fd_socket[cs].fct_write = client_write;
	env->fd_socket[cs].buf_offset = 0;
	env->fd_socket[cs].level = 1;
	env->fd_socket[cs].line = NULL;
	env->fd_socket[cs].line_read = NULL;
	env->fd_socket[cs].my_team = NULL;
	env->fd_socket[cs].incant.x = -1;
	env->fd_socket[cs].incant.y = -1;
	env->fd_socket[cs].last_cmd = 0;
	st_init_inventory(env, cs);
	ft_reply_in_buff(env, cs, "BIENVENUE");
}
