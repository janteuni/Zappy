/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_find_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:32:10 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/14 20:02:36 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

static t_pos			st_find_vector(t_env *env, t_pos rcv, t_pos me)
{
	t_pos				diff;
	t_pos				new;

	printf("REVEIVER %d %d\n", rcv.x, rcv.y);
	printf("ME %d %d\n", me.x, me.y);
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
	printf("NEW %d %d\n", new.x, new.y);
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
	printf("RET ======> %d\n", ret);
	return (ret);
}

static int				st_reoriente(int ret, t_env *env, int cs)
{
	printf("ORIENTATION %d", OR(cs));
	if (ret == 0 || OR(cs) == N)
		return (ret);
	if (OR(cs) == S)
		return (ret + 5);
	if (OR(cs) == E)
		return (ret + 2);
	if (OR(cs) == O)
		return (ret + 7);
	return (ret);
}

void					ft_utils_find_path(t_env *env, int cs)
{
	t_pos				rcv;
	t_pos				me;
	t_pos				new;
	int					i;
	int					ret;

	i = 0;
	me.x = POSX(cs);
	me.y = POSY(cs);
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type == CLIENT && cs != i)
		{
			rcv.x = env->fd_socket[i].pos.x;
			rcv.y = env->fd_socket[i].pos.y;
			new = st_find_vector(env, rcv, me);
			ret = st_define_angle(new, me);
			ret = st_reoriente(ret, env, i);
			printf("RET NOW IS %d\n", ret);
		}
		i++;
	}
}
