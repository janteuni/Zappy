/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 12:41:27 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/11 12:52:45 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include "client.h"

int					ft_forwards(t_env *env)
{
	printf("SENDING COMMAND: AVANCE\n");
	env->resp[RESP_OK]++;
	if ((send(env->socket, FORW, ft_strlen(FORW), 0)) < 0)
	{
		env->resp[RESP_OK]--;
		return (error("Failed to send command"));
	}
	return (OK);
}

int					ft_left(t_env *env)
{
	printf("SENDING COMMAND: LEFT\n");
	env->resp[RESP_OK]++;
	if ((send(env->socket, LEFT, ft_strlen(LEFT), 0)) < 0)
	{
		env->resp[RESP_OK]--;
		return (error("Failed to send command"));
	}
	return (OK);
}

int					ft_right(t_env *env)
{
	printf("SENDING COMMAND: RIGHT\n");
	env->resp[RESP_OK]++;
	if ((send(env->socket, RIGHT, ft_strlen(RIGHT), 0)) < 0)
	{
		env->resp[RESP_OK]--;
		return (error("Failed to send command"));
	}
	return (OK);
}
