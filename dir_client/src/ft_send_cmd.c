/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:06:57 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/19 20:20:51 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include "client.h"

int					ft_send_cmd(t_env *env, char *cmd, int i)
{
	printf("[%d]\tSENDING COMMAND: %s",env->pid, cmd);
	if (i >= 0)
		env->resp[i]++;
	if ((send(env->socket, cmd, ft_strlen(cmd), 0)) < 0)
	{
		printf("[%d]\tSEND WAS UNSUCCESSFUL - return -1\n", env->pid);
		if (i >= 0)
			env->resp[i]--;
		return (error("Failed to send command"));
	}
	return (OK);
}
