/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 18:37:46 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/09 15:30:20 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void			st_pull_inventory(int i, t_env *env, int cs)
{
	env->fd_socket[cs].inventory[i] -= 1;
	env->map[POSY(cs)][POSX(cs)][i] += 1;
	ft_messages_add(env, cs, "ok", 7);
}

void				ft_treat_put(t_env *env, int cs, char *rcv)
{
	char	**split;
	int		i;

	i = 0;
	split = NULL;
	split = ft_super_split(rcv);
	if (ft_tab_len(split) == 2)
	{
		while (i < NB_STUFF)
		{
			if (ft_strcmp(split[1],env->stuff[i]) == 0)
			{
				if (env->fd_socket[cs].inventory[i] > 0)
					st_pull_inventory(i, env, cs);
				else
					ft_messages_add(env, cs, "ko", 7);
				ft_free_tab((void ***)&split);
				return ;
			}
			i++;
		}
	}
	ft_messages_add(env, cs, "ko", 7);
	ft_free_tab((void ***)&split);
}
