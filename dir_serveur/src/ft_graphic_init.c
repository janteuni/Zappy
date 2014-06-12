/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 15:36:37 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/12 15:15:36 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char				*ft_graphic_msz(t_env *env)
{
	char			*str;

	asprintf(&str, "msz %d %d\n", env->width, env->height);
	return (str);
}

char				*ft_graphic_sgt(t_env *env)
{
	char			*str;

	asprintf(&str, "sgt %d\n", env->time);
	return (str);
}

void				ft_graphic_init(t_env *env, int cs)
{
	char			*push;
	int				i;

	i = 0;
	env->fd_socket[cs].type = GRAPHIC;
	env->graphic = cs;
	push = ft_graphic_msz(env);
	ft_reply_in_buff(env, cs, push);
	ft_memdel((void **)&push);
	push = ft_graphic_sgt(env);
	ft_reply_in_buff(env, cs, push);
	ft_memdel((void **)&push);
	ft_graphic_all_map(env, cs);
	push = ft_graphic_tna(env);
	ft_reply_in_buff(env, cs, push);
	ft_memdel((void **)&push);
	while (i < env->max_fd)
	{
		if (env->fd_socket[i].type == CLIENT)
			ft_graphic_reply(env, i, ft_graphic_pnw);
		i++;
	}
}
