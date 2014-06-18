/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 19:05:00 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/18 14:39:46 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "serveur.h"

int				ft_calcul_nb(t_env *env, int cs)
{
	int			ret;
	int			i;

	i = 0;
	ret = 0;
	while (i < env->max_team)
	{
		if (ft_strcmp(env->teams[i].name, env->fd_socket[cs].my_team) == 0)
		{
			ret = env->teams[i].max_player - env->teams[i].nb_player;
			return (ret);
		}
		i++;
	}
	return (ret);
}

int				ft_place_me(t_env *env, int cs)
{
	srand(time(0));
	env->fd_socket[cs].pos.x = rand() % WIDTH;
	env->fd_socket[cs].pos.y = rand() % HEIGHT;
	env->fd_socket[cs].pos.o = rand() % 4;
	if (env->fd_socket[cs].pos.o < 1)
		env->fd_socket[cs].pos.o = 1;
	printf("ORIENTATION : %d\n", OR(cs));
	return (OK);
}
