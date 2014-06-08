/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 16:40:35 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/08 15:26:06 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"

t_env			*get_env(void)
{
	static t_env	*env = NULL;

	if (!env)
	{
		if (!(env = (t_env *)malloc(sizeof(t_env))))
		{
			error("Malloc Failed env");
			return (NULL);
		}
		env->addr = NULL;
		env->port = 0;
		env->dead = 0;
		env->level = 1;
		env->team = NULL;
	}
	return (env);
}
