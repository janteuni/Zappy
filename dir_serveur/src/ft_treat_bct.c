/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_bct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 12:12:52 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 12:29:15 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void				ft_treat_bct(t_env *env, int cs, char *rcv)
{
	char			*str;
	char			**split;
	int				y;
	int				x;

	split = NULL;
	split = ft_super_split(rcv);
	if (ft_tab_len(split) == 3)
	{
		y = ft_atoi(split[2]);
		x = ft_atoi(split[1]);
		if (x <= WIDTH - 1 && y <= HEIGHT - 1)
		{
			str = ft_graphic_bct(env, x, y);
			if (env->graphic != -1)
				ft_reply_in_buff(env, env->graphic, str);
			ft_memdel((void **)&str);
			return ;
		}
	}
	ft_graphic_reply(env, cs, ft_graphic_sbp);
}
