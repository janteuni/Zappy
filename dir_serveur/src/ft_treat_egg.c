/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_egg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:40:17 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/13 12:23:48 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_egg(t_env *env, int cs, char *rcv)
{
	int				i;

	i = 0;
	(void)rcv;
	printf("EGG IS OOOOOOKKKKK\n");
	while (i < env->max_team)
	{
		if (ft_strcmp(env->teams[i].name, env->fd_socket[cs].my_team) == 0)
		{
			env->teams[i].max_player++;
			break ;
		}
		i++;
	}
	ft_graphic_reply(env, cs, ft_graphic_eht);
}
