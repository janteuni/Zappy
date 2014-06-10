/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 18:36:41 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/10 15:44:33 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_eat(t_env *env)
{
	int				i;

	i = 0;
	printf("I EAT\n");
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type == CLIENT)
		{
			env->fd_socket[i].inventory[FOOD] -= 1;
			if (env->fd_socket[i].inventory[FOOD] <= 0)
			{
				ft_reply_in_buff(env, i, "mort");
			}
		}
		i++;
	}
}
