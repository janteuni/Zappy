/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_reply.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 14:18:42 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 15:49:01 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int					ft_graphic_reply(t_env *env, int cs, char *(*fn)())
{
	char			*line;

	line = NULL;
	if (env->graphic != -1)
	{
		line = fn(env, cs);
		if (line != NULL)
		{
			ft_reply_in_buff(env, env->graphic, line);
			ft_memdel((void **)&line);
		}
		else
			return (ERR);
		return (OK);
	}
	return (ERR);
}
