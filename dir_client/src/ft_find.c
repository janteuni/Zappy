/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 20:10:30 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/24 22:16:29 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "client.h"

int					ft_random(t_env *env)
{
	int				n;

	srand(time(NULL));
	n = rand() % 8;
	if (n == 1 || n == 0)
		ft_push_cmd(env, AVANCE, NULL, RESP_OK);
	else if (n < 6)
		ft_dir_left(env, n);
	else
		ft_dir_right(env, n);
	env->dir_chg = 0;
	return (OK);
}

static int			ft_take_all(t_env *env)
{
	int				i;

	i = 0;
	while (i < 8)
	{
		ft_push_cmd(env, PREND, ft_strdup(ft_get_str(FOOD)), RESP_OK);
		++i;
	}
	return (OK);
}

static void			ft_look_around(t_env *env)
{
	if (env->dir_chg < 4)
	{
		ft_push_cmd(env, DROITE, NULL, RESP_OK);
		env->dir_chg++;
	}
	else
	{
		env->dir_chg = 0;
		ft_random(env);
	}
}

static int			ft_find_nearest(t_env *env, int obj)
{
	int				i;
	int				c;

	c = -1;
	i = 1;
	while (i < env->view_size)
	{
		if (env->view[i][obj] > 0
				&& (c < 0 || env->view[c][DIST] > env->view[i][DIST]))
		{
			if (obj == FOOD || env->view[i][PLAYERS] < 4)
				c = i;
		}
		++i;
	}
	if (c < 0)
		return (NO);
	env->dir_chg = 0;
	ft_get_route(env, c);
	return (YES);
}

int					ft_find(t_env *env, int obj)
{
	if (env->view_size < ((env->level + 1) * (env->level + 1)))
	{
		ft_push_cmd(env, VOIR, NULL, RESP_VIEW);
		return (OK);
	}
	if (env->view[0][obj] == 0)
	{
		if (!ft_find_nearest(env, obj))
		{
			ft_look_around(env);
			return (OK);
		}
	}
	if (obj == FOOD)
		ft_take_all(env);
	else
		ft_push_cmd(env, PREND, ft_strdup(ft_get_str(obj)), RESP_OK);
	return (OK);
}
