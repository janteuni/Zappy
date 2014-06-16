/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_plv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <janteuni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 17:24:59 by janteuni          #+#    #+#             */
/*   Updated: 2014/06/16 17:58:51 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void					ft_treat_plv(t_env *env, int cs, char *rcv)
{
	int					player;
	char				**split;

	(void)cs;
	split = NULL;
	split = ft_super_split(rcv);
	if (ft_tab_len(split) == 2)
	{
		player = ft_atoi(split[1]);
		if (ft_graphic_reply(env, player, ft_graphic_plv) == ERR)
			ft_graphic_reply(env, cs, ft_graphic_sbp);
	}
	else
		ft_graphic_reply(env, cs, ft_graphic_sbp);
}
