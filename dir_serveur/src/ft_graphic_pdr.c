/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_pdr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 11:15:21 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 18:04:39 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void					ft_graphic_pdr(t_env *env, int cs, int i)
{
	char				*str;

	str = NULL;
	if (env->graphic != -1)
	{
		if (cs >= 0 && cs < env->max_fd && env->fd_socket[cs].type == CLIENT)
		{
			asprintf(&str, "pdr %d %d\n", cs, i);
			ft_reply_in_buff(env, env->graphic, str);
			ft_memdel((void **)&str);
		}
	}
}
