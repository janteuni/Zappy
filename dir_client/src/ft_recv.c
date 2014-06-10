/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 16:22:18 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/10 11:48:32 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int					is_dead(t_env *env, char *buf)
{
	if (!ft_strncmp(DEAD, buf, ft_strlen(DEAD)))
	{
		printf("I DIED - %s\n", buf);
		env->dead = 1;
		return (YES);
	}
	else
		return (NO);
}

int					is_move(t_env *env, char *buf)
{
	char			**split;
	int				dir;

	if (!ft_strncmp(MOVE, buf, ft_strlen(MOVE)))
	{
		printf("I WAS MOVED - %s\n", buf);
		split = ft_strsplit(buf, ' ');	/*do i need any of this?*/
		dir = ft_atoi(split[1]);		/**/
		if (dir == N)					/**/
			env->y++;					/**/
		if (dir == E)					/**/
			env->x--;					/**/
		if (dir == S)					/**/
			env->y--;					/**/
		if (dir == W)					/**/
			env->x++;					/**/
		ft_free_tab((void ***)&split);	/**/
		return (YES);
	}
	return (NO);
}

int					is_msg(t_env *env, char *buf)
{
	if (!ft_strncmp(MSG, buf, ft_strlen(MSG)))
	{
		printf("I GOT A MSG - %s\n", buf);
		ft_treat_msg(env, buf);
		return (YES);
	}
	return (NO);
}

int					is_elev(t_env *env, char *buf)
{
	if (!ft_strncmp(ELEV, buf, ft_strlen(ELEV)))
	{
		printf("I AM BEING ELEVATED - %s\n", buf);
		if (enough_food(env))
			env->elevating = 1;
		else
			env->get_food = 1;
		return (YES);
	}
	return (NO);
}

int					ft_recv(t_env *env)
{
	char			buf[BIG_BUF + 1];

	ft_bzero(buf, BIG_BUF + 1);
	recv(env->socket, buf, BIG_BUF, 0);
	if (!is_dead(env, buf) && !is_move(env, buf) && !is msg(env, buf)
			&& !is elev(env, buf) && !is_elev_end(env, buf))
		check_expected(env, buf);
}
