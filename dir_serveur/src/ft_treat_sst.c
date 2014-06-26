/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_sst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 11:16:19 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/17 11:21:20 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void		ft_treat_sst(t_env *env, int cs, char *rcv)
{
	char	**split;
	char	*str;
	int		timer;

	str = NULL;
	split = NULL;
	split = ft_super_split(rcv);
	if (ft_tab_len(split) == 2)
	{
		timer = ft_atoi(split[1]);
		if (timer > 0)
		{
			env->time = timer;
			str = ft_graphic_sgt(env);
			if (env->graphic != -1)
				ft_reply_in_buff(env, env->graphic, str);
			ft_memdel((void **)&str);
		}
		else
			ft_graphic_reply(env, cs, ft_graphic_sbp);
	}
	else
		ft_graphic_reply(env, cs, ft_graphic_sbp);
}
