/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elevation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 14:49:52 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/20 20:12:47 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "client.h"

int					ft_enough_food(t_env *env)
{
	/* CHECK INVENTORY FIRST? JUST HOPE THAT ITS CORRECT? */
	if (env->inv[FOOD] < 8)
		return (NO);
	else
		return (YES);
}


int					ft_begin_elev(t_env *env, char *buf)
{
	(void)buf;
	if (!env->my_incant && env->view[0][FOOD] > 0/*ft_enough_food(env)*/)
		env->elevating = 1;
	else if (!env->my_incant && env->view[0][FOOD] == 0 && !ft_enough_food(env))
		env->elevating = 0;
	return (OK);
}

int					ft_end_elev(t_env *env, char *buf)
{
	char			*ptr;
	int				new_level;

	ptr = ft_strchr(buf, ':');
	new_level = 0;
	env->my_incant = 0;
	if (ptr && ptr[0] && ptr[1] && ptr[2])
		new_level = ft_atoi(&ptr[2]);
	else
	{
		dprintf( env->aff, "I don't understand '%s'\n", buf);
		return (ERR);
	}
	env->elevating = 0;
	if (new_level < 1)
	{
		printf("NEW LEVEL IS [%d] - MAIS ALLO QUOI? \n", new_level);
		return (ERR);
	}
	if (new_level != env->level)
	{
		/*	env->forked = 0;
			env->laying = 0;*/
		env->dir_msg = -1;
	/*	if (new_level == 4)
			env->forked = 0;*/
	}
	env->level = new_level;
	return (OK);
}

int					ft_elev_failed(t_env *env)
{
	env->elevating = 0;
	return (OK);
}
