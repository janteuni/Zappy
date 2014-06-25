/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elevation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 14:49:52 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/24 20:00:24 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "client.h"

int					ft_enough_food(t_env *env)
{
	if (env->inv[FOOD] < 8)
		return (NO);
	else
		return (YES);
}

int					ft_begin_elev(t_env *env, char *buf)
{
	(void)buf;
	if (!env->my_incant && env->view[0][FOOD] > 0)
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
		return (ERR);
	env->elevating = 0;
	if (new_level < 1)
		return (ERR);
	if (new_level != env->level)
	{
		env->dir_msg = -1;
	}
	env->level = new_level;
	return (OK);
}

int					ft_elev_failed(t_env *env)
{
	env->elevating = 0;
	return (OK);
}
