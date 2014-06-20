/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_stones.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:26:04 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/20 18:48:20 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

/* The stone are numbered from 1 - 6, so there are 6 in total (NB_STONES = 6) */
int					ft_find_stones(t_env *env)
{
	int				stone;
	int				i;
	int				need;
	int				to_take;

	stone = 1;
	while (env->inv[stone] >= env->incantation[env->level + 1][stone]
			&& stone <= NB_STONES)
		++stone; //to get to the first stone that you dont have enough of
/*	dprintf(env->aff, "LOOKING FOR STONE [%d]\n",stone );*/
	need = env->incantation[env->level + 1][stone] - env->inv[stone];
	if (need > 0)
	{
		if (need <= env->view[0][stone])
			to_take = need;
		else
			to_take = env->view[0][stone];
		if (to_take)
		{
			i = 0;
			while (i < to_take)
			{
				ft_push_cmd(env, PREND, ft_strdup(ft_get_str(stone)), RESP_OK);
				++i;
			}
		}
		else
			ft_find(env, stone);
	}
	return (OK);
}
