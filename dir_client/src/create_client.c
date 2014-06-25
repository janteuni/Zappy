/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 19:30:52 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/24 19:57:09 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "client.h"

int						ft_get_hostbyname(t_env *env)
{
	struct hostent		*hp;
	struct in_addr		**addr_list;
	char				*tmp;

	addr_list = NULL;
	if ((hp = gethostbyname(env->addr)) == NULL)
		return (ERR);
	addr_list = (struct in_addr **)hp->h_addr_list;
	tmp = env->addr;
	env->addr = inet_ntoa(*addr_list[0]);
	ft_strdel(&tmp);
	return (OK);
}

int						create_client(t_env *env)
{
	struct protoent		*proto;
	struct sockaddr_in	sin;
	struct in_addr		ip;

	if (!inet_aton(env->addr, &ip))
	{
		if (ft_get_hostbyname(env) < 0)
			return (ERR);
	}
	proto = getprotobyname("tcp");
	if (!proto)
		return (error("Proto error"));
	if ((env->socket = socket(PF_INET, SOCK_STREAM, proto->p_proto)) < 0)
		return (error("Socket error"));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(env->port);
	sin.sin_addr.s_addr = inet_addr(env->addr);
	if (-1 == connect(env->socket, (const struct sockaddr *)&sin, sizeof(sin)))
		return (error("Failed to connect to server"));
	return (OK);
}
