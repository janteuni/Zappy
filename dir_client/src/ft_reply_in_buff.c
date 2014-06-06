/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reply_in_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 12:24:49 by janteuni          #+#    #+#             */
/*   Updated: 2014/05/22 19:24:09 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_reply_in_buff(t_env *env, int cs, char *msg)
{
	char			*res;
	char			*tmp;

	res = ft_strdup(msg);
	if (res && res[ft_strlen(res) - 1] != '\n')
	{
		tmp = ft_strjoin(res, "\n");
		ft_memdel((void **)&res);
		res = tmp;
	}
	ft_strncpy(env->fd_socket[cs].buf_write, res, ft_strlen(res));
	ft_memdel((void **)&res);
}
