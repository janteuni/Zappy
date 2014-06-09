/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 19:39:44 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/09 22:13:39 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include "client.h"

void				ft_print_inv(t_env *env)
{
	int				i;

	i = 0;
	while (i < INV_SIZE)
	{
		printf("INVENTORY[%d] has %d\n",i, env->inv[i] );
		++i;
	}
}

int					ft_revc(_env *env)
{
	char			buf[BIG_BUF + 1];

	recv(env->socket, buf, BIG_BUF, 0);
	if (ft_strncmp(buf, DEAD, ft_strlen(DEAD))
			|| ft_strncmp(buf, MOVE, ft_strlen(MOVE))
			|| ft_strncmp(buf, MSG, ft_strlen(MSG))
			|| ft_strncmp(buf, ELEV, ft_strlen(ELEV)))
	{

	}


	return (OK);
}

int					ft_loop(t_env *env)
{
	ft_get_inventory(env);
	while (!env->dead)
	{
/*		ft_recv(env);
		ft_action(ev);*/
		ft_get_inventory(env);
		ft_print_inv(env);
		ft_look(env);
		env->dead = 1;
		/*ft_takemove(env);*/
	}
	return (OK);
}
