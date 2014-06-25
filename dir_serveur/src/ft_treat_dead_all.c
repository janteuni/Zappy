/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_dead_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 19:01:40 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/25 17:04:46 by janteuni         ###   ########.fr       */
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
		if (env->fd_socket[i].type == CLIENT && i != env->graphic)
		{
			printf("mort de %d LEVEL %d\n", i, env->fd_socket[i].level);
			ft_reply_in_buff(env, i, "mort");
			ft_graphic_reply(env, i, ft_graphic_pdi);
		}
		i++;
	}
}
