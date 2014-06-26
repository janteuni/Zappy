/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_find_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:32:10 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/19 11:41:36 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

static t_pos			st_find_vector(t_env *env, t_pos rcv, t_pos me)
{
	t_pos				diff;
	t_pos				new;

	diff.x = rcv.x - me.x;
	diff.y = rcv.y - me.y;
	if (abs(diff.x) > WIDTH / 2)
	{
		if (diff.x < WIDTH / 2)
			new.x = rcv.x + WIDTH;
		else
			new.x = rcv.x - WIDTH;
	}
	else
		new.x = rcv.x;
	if (abs(diff.y) > HEIGHT / 2)
	{
		if (diff.y < HEIGHT / 2)
			new.y = rcv.y + HEIGHT;
		else
			new.y = rcv.y - HEIGHT;
	}
	else
		new.y = rcv.y;
	return (new);
}

static void				st_diagonale(int *ret, t_pos me, t_pos rcv)
{
	if (me.x < rcv.x && me.y < rcv.y)
		*ret = 2;
	else if (me.x > rcv.x && me.y > rcv.y)
		*ret = 6;
	else if (me.x > rcv.x && me.y < rcv.y)
		*ret = 8;
	else if (me.x < rcv.x && me.y > rcv.y)
		*ret = 4;
}

static int				st_define_angle(t_pos rcv, t_pos me)
{
	t_pos				diff;
	int					ret;

	ret = 0;
	diff.x = rcv.x - me.x;
	diff.y = rcv.y - me.y;
	if (rcv.x == me.x && rcv.y == me.y)
		ret = 0;
	else if (me.y > rcv.y && abs(diff.x) != abs(diff.y))
		ret = 5;
	else if (me.y < rcv.y && abs(diff.x) != abs(diff.y))
		ret = 1;
	else if (me.x > rcv.x && abs(diff.x) != abs(diff.y))
		ret = 3;
	else if (me.x < rcv.x && abs(diff.x) != abs(diff.y))
		ret = 7;
	else
		st_diagonale(&ret, me, rcv);
	return (ret);
}

static int				st_reoriente(int ret, t_env *env, int cs)
{
	if (ret == 0 || OR(cs) == N)
		return (ret);
	if (OR(cs) == S)
		ret = ret <= 4 ? ret + 4 : ret - 4;
	else if (OR(cs) == E)
		ret = ret >= 7 ? ret - 6 : ret + 2;
	else if (OR(cs) == O)
		ret = ret <= 2 ? ret + 6 : ret - 2;
	return (ret);
}

int						ft_utils_find_path(t_env *env, int cs, int i)
{
	t_pos				rcv;
	t_pos				me;
	t_pos				new;
	int					ret;

	ret = 0;
	me.x = POSX(cs);
	me.y = POSY(cs);
	if (env->fd_socket[i].type == CLIENT && cs != i)
	{
		rcv.x = env->fd_socket[i].pos.x;
		rcv.y = env->fd_socket[i].pos.y;
		new = st_find_vector(env, rcv, me);
		ret = st_define_angle(new, me);
		ret = st_reoriente(ret, env, i);
	}
	return (ret);
}
