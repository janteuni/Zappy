/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_broadcast.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 12:42:49 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/17 16:42:10 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void			st_contact_all(char *rcv, int i, t_env *env, int cs)
{
	int				j;
	int				ret;
	char			*msg;

	j = 0;
	ret = 0;
	msg = NULL;
	while (j < env->max_fd)
	{
		if (env->fd_socket[j].type == CLIENT && cs != j)
		{
			ret = ft_utils_find_path(env, cs, j);
			asprintf(&msg, "message %d, %s\n", ret, rcv + i);
			ft_reply_in_buff(env, j, msg);
			ft_memdel((void **)&msg);
		}
		j++;
	}
}

void				ft_treat_broadcast(t_env *env, int cs, char *rcv)
{
	int				i;
	char			**split;
	char			*line;

	i = 9;
	split = ft_super_split(rcv);
	if (ft_tab_len(split) >= 2)
	{
		while (rcv[i] == ' ')
			i++;
		st_contact_all(rcv, i, env, cs);
		line = ft_graphic_pbc(env, cs, rcv + i);
		if (env->graphic != -1)
			ft_reply_in_buff(env, env->graphic, line);
		ft_memdel((void **)&line);
		ft_reply_in_buff(env, cs, "ok");
	}
	else
		ft_reply_in_buff(env, cs, "ko");
	ft_free_tab((void ***)&split);
}
