/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 17:45:22 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/13 11:26:50 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void			st_fill_inventory(int i, t_env *env, int cs)
{
	env->fd_socket[cs].inventory[i]++;
	env->map[POSY(cs)][POSX(cs)][i] -= 1;
	ft_reply_in_buff(env, cs, "ok");
	ft_graphic_pgt(env, cs, i);
}

void				ft_treat_get(t_env *env, int cs, char *rcv)
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
			if (ft_strcmp(split[1], env->stuff[i]) == 0)
			{
				if (env->map[POSY(cs)][POSX(cs)][i] > 0)
					st_fill_inventory(i, env, cs);
				else
					ft_reply_in_buff(env, cs, "ko");
				ft_free_tab((void ***)&split);
				return ;
			}
			i++;
		}
	}
	ft_reply_in_buff(env, cs, "ko");
	ft_free_tab((void ***)&split);
}
