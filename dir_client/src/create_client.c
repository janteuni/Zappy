/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 19:30:52 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/07 18:51:51 by fbeck            ###   ########.fr       */
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
	struct hostent		*hp;
	struct in_addr		**addr_list;

	addr_list = NULL;
	printf("can't parse IP address %s\n", env->addr);
	if ((hp = gethostbyname(env->addr)) == NULL)
	{
		printf("no name associated with %s", env->addr);
		return (ERR);
	}
	addr_list = (struct in_addr **)hp->h_addr_list;
	env->addr = inet_ntoa(*addr_list[0]);
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
	printf("GOING TO CONNECT:\nPORT [%d] ADDR [%s] \n", env->port, env->addr);
	proto = getprotobyname("tcp");
	if (!proto)
		return (error("Proto error"));
	if ((env->socket = socket(PF_INET, SOCK_STREAM, proto->p_proto)) < 0)
		return (error("Socket error"));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(env->port);
	sin.sin_addr.s_addr = inet_addr(env->addr);
	if ( -1 == connect(env->socket,(const struct sockaddr *)&sin, sizeof(sin)))
		return (error("Failed to connect to server"));
	return (OK);
}
