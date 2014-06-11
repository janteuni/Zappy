/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elevation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 14:49:52 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/11 18:06:47 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int					ft_enough_food(t_env *env)
{
	/* CHECK INVENTORY FIRST? JUST HOPE THAT ITS CORRECT? */
	if (env->inv[FOOD] < 3)
		return (NO);
	else
		return (YES);
}


int					ft_begin_elev(t_env *env, char *buf)
{
	(void)buf;
	if (ft_enough_food(env))
		env->elevating = 1;
	else
		env->elevating = 0;
	return (OK);
}

int					ft_end_elev(t_env *env, char *buf)
{
	char			*ptr;
	int				new_level;

	ptr = ft_strchr(buf, ':');
	new_level = 0;
	if (ptr[1] && ptr[2])
		new_level = ft_atoi(&ptr[2]);
	if (new_level < 1)
		return (ERR);
	env->level = new_level;
	return (OK);
}
