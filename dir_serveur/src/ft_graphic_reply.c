/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_reply.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 14:18:42 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/13 11:20:01 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_graphic_reply(t_env *env, int cs, char *(*fn)())
{
	char			*line;

	line = NULL;
	if (env->graphic != -1)
	{
		line = fn(env, cs);
		ft_reply_in_buff(env, env->graphic, line);
		ft_memdel((void **)&line);
	}
}
