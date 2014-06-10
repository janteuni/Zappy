/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 19:39:44 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/10 19:47:20 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include "client.h"

int					ft_takemove(t_env *env)
{
	if (env->elevating)
		return (OK);


}

int					ft_loop(t_env *env)
{
	/*int				i;
	char			*str;

	i = 0;
	str = ft_strjoin("avance\n", "gauche\n");
	printf("STR SENT -%s\n",str );
	if ((send(env->socket, str, ft_strlen(str), 0)) < 0)
		return (error("Failed to send command"));*/
	ft_look(env);
	while (!env->dead)
	{
		ft_recv(env);
		ft_takemove(env);
		i++;
	}
	return (OK);
}
