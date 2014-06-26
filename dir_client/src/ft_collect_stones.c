/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect_stones.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 22:15:09 by fbeck             #+#    #+#             */
/*   Updated: 2014/06/24 22:15:12 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void				ft_collect_stones(t_env *env)
{
	int				stone;
	int				i;
	int				need;
	int				to_take;

	stone = 1;
	while (env->inv[stone] >= env->incantation[env->level + 1][stone]
			&& stone <= NB_STONES)
		++stone;
	need = env->incantation[env->level + 1][stone] - env->inv[stone];
	if (need > 0)
	{
		to_take = (need <= env->view[0][stone] ? need : env->view[0][stone]);
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
}
