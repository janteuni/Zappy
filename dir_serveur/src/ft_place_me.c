/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 19:05:00 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/12 12:17:46 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "serveur.h"

static int		st_calcul_nb(t_env *env, int cs)
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

static void		st_my_position(t_env *env, int cs)
{
	char		*ret;
	char		*tmp;
	char		*itoa;

	itoa = ft_itoa(st_calcul_nb(env, cs));
	ret = ft_strjoin(itoa, "\n");
	ft_memdel((void **)&itoa);
	itoa = ft_itoa(env->fd_socket[cs].pos.x);
	tmp = ft_strjoin(ret, itoa);
	ft_memdel((void **)&ret);
	ft_memdel((void **)&itoa);
	itoa = ft_itoa(env->fd_socket[cs].pos.y);
	ret = ft_strjoin(tmp, " ");
	ft_memdel((void **)&tmp);
	tmp = ft_strjoin(ret, itoa);
	ft_reply_in_buff(env, cs, tmp);
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&ret);
	ft_memdel((void **)&itoa);
}

int				ft_place_me(t_env *env, int cs)
{
	srand(time(0));
	env->fd_socket[cs].pos.x = rand() % WIDTH;
	env->fd_socket[cs].pos.y = rand() % HEIGHT;
	env->fd_socket[cs].pos.o = N;
	st_my_position(env, cs);
	return (OK);
}
