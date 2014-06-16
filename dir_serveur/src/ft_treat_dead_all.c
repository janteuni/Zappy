/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_dead_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 19:01:40 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 19:06:11 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "serveur.h"

void				ft_treat_dead_all(t_env *env)
{
	int				i;

	i = 0;
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type == CLIENT)
		{
			printf("mort de %d\n", i);
			send(i, "mort", 4, 0);
			ft_graphic_reply(env, i, ft_graphic_pdi);
			clean_fd(&env->fd_socket[i]);
		}
		i++;
	}
}
