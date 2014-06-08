/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 19:39:44 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/08 19:48:03 by fbeck            ###   ########.fr       */
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

int					ft_loop(t_env *env)
{
	while (!env->dead)
	{
		ft_get_inventory(env);
		ft_print_inv(env);
		ft_look(env);
		env->dead = 1;
		/*ft_takemove(env);*/
	}
	return (OK);
}
