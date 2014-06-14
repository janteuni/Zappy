/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:06:57 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/14 20:08:50 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include "client.h"

int					ft_send_cmd(t_env *env, char *cmd, int i)
{
	printf("SENDING COMMAND: %s", cmd);
	printf("incresing the response table\n");
	if (i >= 0)
		env->resp[i]++;
	if ((send(env->socket, cmd, ft_strlen(cmd), 0)) < 0)
	{
		printf("SEND WAS UNSICCESSFUL - return -1\n");
		if (i >= 0)
			env->resp[i]--;
		return (error("Failed to send command"));
	}
	printf("SEND WAS SUCCESSFUL\n");
	return (OK);
}
