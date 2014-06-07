/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 17:10:59 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/07 15:40:01 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "serveur.h"

int						create_server(t_env *env)
{
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (error("error proto"));
	env->sock_server = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(env->port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(env->sock_server,
				(const struct sockaddr *)&sin, sizeof(sin)) == -1)
		return (error("bind failed"));
	listen(env->sock_server, 42);
	env->fd_socket[env->sock_server].type = SERVER;
	env->fd_socket[env->sock_server].fct_read = server_accept;
	return (OK);
}
