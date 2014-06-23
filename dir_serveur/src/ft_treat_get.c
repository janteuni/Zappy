/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 17:45:22 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/23 12:05:43 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void			st_fill_inventory(int i, t_env *env, int cs)
{
	char			*line;

	line = NULL;
	env->fd_socket[cs].inventory[i]++;
	if (i != FOOD)
		env->map[POSY(cs)][POSX(cs)][i] -= 1;
	ft_reply_in_buff(env, cs, "ok");
	ft_graphic_pgt(env, cs, i);
	ft_graphic_reply(env, cs, ft_graphic_pin);
	line = ft_graphic_bct(env, POSX(cs), POSY(cs));
	if (env->graphic != -1)
		ft_reply_in_buff(env, env->graphic, line);
	ft_memdel((void **)&line);
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
